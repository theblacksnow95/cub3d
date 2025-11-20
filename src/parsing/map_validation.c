/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:25:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/19 18:23:11 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_exit(t_cub *data)
{
	if (data)
	{
		free_struct(data);
		data = NULL;
		exit (1);
	}
}

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
			if (!is_valid_char(map[y][x], data) || data->ply > 1)
				return (error_handler(NULL, E_MAP, EMPTY_ID, data), 0);
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
		free_exit(data);
		return ;
	}
	locate_player(data);
	if (fill_validation(data->map, data->y_p, data->x_p))
	{
		error_handler(data->line, E_MAP, NO_ID, data);
		free_exit(data);
	}
	ft_printf(CLR_GRN"MAP <%s> CORRECT\n"RST_ALL, data->map_path);
}
