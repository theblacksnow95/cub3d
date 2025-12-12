/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:32 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/12 15:06:19 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	If `raydir` is 0, we use a very large number (1e30) to represent 
	"never cross."
*/
static void	ray_init(t_cub *game, t_ray *ray, int j)
{
	ray->camerax = 2.0 * j / (double)WIN_W - 1.0;
	ray->raydirx = game->player.dir_x + game->player.plane_x * ray->camerax;
	ray->raydiry = game->player.dir_y + game->player.plane_y * ray->camerax;
	ray->mapx = (int)game->player.x;
	ray->mapy = (int)game->player.y;
	if (ray->raydirx == 0.0)
		ray->deltax = 1e30;
	else
		ray->deltax = fabs(1.0 / ray->raydirx);
	if (ray->raydiry == 0.0)
		ray->deltay = 1e30;
	else
		ray->deltay = fabs(1.0 / ray->raydiry);
}

/*
	stepx/Y = the direction the ray travels on the grid.
	sidex/Y = the distance from the player's position to the first
*/
static void	ray_step_init(t_cub *game, t_ray *ray)
{
	if (ray->raydirx < 0.0)
	{
		ray->stepx = -1;
		ray->sidex = (game->player.x - ray->mapx) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->sidex = (ray->mapx + 1.0 - game->player.x) * ray->deltax;
	}
	if (ray->raydiry < 0.0)
	{
		ray->stepy = -1;
		ray->sidey = (game->player.y - ray->mapy) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->sidey = (ray->mapy + 1.0 - game->player.y) * ray->deltay;
	}
}

/*
	distance in X 	= (X integer of next cell) - player position
					= (mapx + 1) - player.x
*/
static int	cast_single_ray(t_cub *game, int j)
{
	t_texture	*text;

	ray_init(game, &game->ray, j);
	ray_step_init(game, &game->ray);
	dda(game, &game->ray);
	if (game->ray.side == 0)
		game->ray.perpdist = (game->ray.sidex - game->ray.deltax);
	else
		game->ray.perpdist = (game->ray.sidey - game->ray.deltay);
	if (game->ray.perpdist < 0.01)
		game->ray.perpdist = 0.01;
	game->ray.line_h = (int)(WIN_H / game->ray.perpdist);
	game->draws = -game->ray.line_h / 2 + WIN_H / 2;
	if (game->draws < 0)
		game->draws = 0;
	game->drawe = game->ray.line_h / 2 + WIN_H / 2;
	if (game->drawe >= WIN_H)
		game->drawe = WIN_H - 1;
	text = select_texture(game, &game->ray);
	if (put_v_texture(game, text, j))
		return (1);
	return (0);
}

/*
I scan all the columns of the screen, shooting a ray at each one.
*/
int	cast_all_rays(t_cub *game)
{
	int	j;

	j = 0;
	while (j < WIN_W)
	{
		if (cast_single_ray(game, j))
			return (perror("doing raycast"), 1);
		j++;
	}
	return (0);
}
