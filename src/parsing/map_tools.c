/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:22:35 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/21 12:37:31 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c);

int	is_valid(char c)
{
	if (is_player(c) || c == '1' || c == '0' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	locate_player(t_cub *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (is_player(data->map[y][x]))
			{
				data->player.x = x;
				data->player.y= y;
				printf(CLR_YLLW"Player position: map[%f][%f]\n"RST_ALL, data->player.y, data->player.x); // debug
				return (1);
			}
			if (!is_valid(data->map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (0);
}

