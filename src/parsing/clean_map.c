/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:25:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/17 16:10:51 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c, t_cub *data)
{
	if (c == '1' || c == '0' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		data->ply++;
		return (1);
	}
	else
		return (0);
}

int	valid_chars(t_cub *data, char **map, int y, int x)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_valid_char(map[y][x], data) && data->ply > 1)
				return (ft_printf("Error\nInvalid map\n"), 0); //debug
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_map(t_cub *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!valid_chars(data, data->map, y, x))
	{
		free_struct(data);
		return ;
	}
}
