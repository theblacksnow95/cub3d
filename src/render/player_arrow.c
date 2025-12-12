/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:02:55 by antuel            #+#    #+#             */
/*   Updated: 2025/12/12 15:10:44 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Part of Bresenham's algorithm
*/
static void	draw_line_loop(t_mlx *mlx, t_line_print_dir *dir)
{
	while (1)
	{
		my_mlx_pixel_put(mlx, dir->x0, dir->y0, dir->color);
		if (dir->x0 == dir->x1 && dir->y0 == dir->y1)
			break ;
		dir->e2 = dir->err * 2;
		if (dir->e2 > -dir->dy)
		{
			dir->err -= dir->dy;
			dir->x0 += dir->sx;
		}
		if (dir->e2 < dir->dx)
		{
			dir->err += dir->dx;
			dir->y0 += dir->sy;
		}
	}
}

static void	draw_line(t_mlx *mlx, t_line_print_dir dir)
{
	dir.dx = dir.x1 - dir.x0;
	if (dir.dx < 0)
		dir.dx = -dir.dx;
	dir.dy = dir.y1 - dir.y0;
	if (dir.dy < 0)
		dir.dy = -dir.dy;
	dir.sx = 1;
	if (dir.x0 > dir.x1)
		dir.sx = -1;
	dir.sy = 1;
	if (dir.y0 > dir.y1)
		dir.sy = -1;
	dir.err = dir.dx - dir.dy;
	draw_line_loop(mlx, &dir);
}

void	draw_player_arrow(t_cub *game)
{
	t_line_print_dir	line;
	double				px;
	double				py;
	double				dx;

	px = game->player.x * TILE_SIZE;
	py = game->player.y * TILE_SIZE;
	dx = game->player.dir_x;
	line.color = 0xFFFFFF;
	line.x0 = (int)(px + dx * 15);
	line.y0 = (int)(py + game->player.dir_y * 15);
	line.x1 = (int)(px + dx * 8 - game->player.dir_y * 5);
	line.y1 = (int)(py + game->player.dir_y * 8 + dx * 5);
	draw_line(&game->mlx, line);
	line.x1 = (int)(px + dx * 8 + game->player.dir_y * 5);
	line.y1 = (int)(py + game->player.dir_y * 8 - dx * 5);
	draw_line(&game->mlx, line);
	line.x0 = (int)(px + dx * 8 - game->player.dir_y * 5);
	line.y0 = (int)(py + game->player.dir_y * 8 + dx * 5);
	draw_line(&game->mlx, line);
}
