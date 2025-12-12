/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:14:15 by antuel            #+#    #+#             */
/*   Updated: 2025/12/12 15:09:14 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	si selections es 1, es el ceiling, sino es floor
*/
void	clear_window_select(t_mlx *mlx, int color, bool selection)
{
	int	x;
	int	y;
	int	divh;
	int	divw;

	y = 0;
	divh = WIN_H;
	divw = WIN_W;
	if (selection)
		divh -= WIN_H / 2;
	else
		y = WIN_H / 2;
	while (y < divh)
	{
		x = 0;
		while (x < divw)
		{
			my_mlx_pixel_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

int	draw_player(t_mlx *mlx, double px, double py, int color)
{
	int	i;
	int	j;
	int	radius;

	radius = PLAYER_RAD;
	i = -radius;
	px = px * TILE_SIZE;
	py = py * TILE_SIZE;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
			{
				if (my_mlx_pixel_put(mlx, (int)px + j, (int)py + i, color))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
	cell offset to set color
*/
int	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
	{
		return (0);
	}
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
	return (0);
}

/*function to draw a square*/
static int	draw_square(t_mlx *mlx, int w, int h, int color)
{
	int		x;
	int		y;
	int		start_y;
	int		start_x;

	y = 0;
	start_y = h * TILE_SIZE;
	start_x = w * TILE_SIZE;
	while (y < TILE_SIZE)
	{
		if (start_y + y >= WIN_H || start_y + y < 0)
			break ;
		x = 0;
		while (x < TILE_SIZE)
		{
			if (start_x + x >= WIN_W || start_x + x < 0)
				break ;
			if (my_mlx_pixel_put(mlx, start_x + x, start_y + y, color))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_map(t_cub *game)
{
	int		y;
	int		x;
	int		error;
	char	cell;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			cell = game->map[y][x];
			if (cell == '1' || cell == ' ')
				error = draw_square(&game->mlx, x, y, 0x00FFFF);
			else
				error = draw_square(&game->mlx, x, y, 0x808080);
			if (error)
				close_windows(game);
			x++;
		}
		y++;
	}
	draw_player(&game->mlx, game->player.x, game->player.y, 0x000FF0);
	draw_player_arrow(game);
	return (0);
}
