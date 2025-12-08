/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:32 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/08 12:06:55 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_vertical_line( t_mlx *mlx, int col, int drawstart, int drawend, int color)
{
	int	j;

	if (col < 0 || col >= WIN_W)
		return (perror("printing vertical line"), 1);
	if (drawstart < 0)
		drawstart = 0;
	if (drawend >= WIN_H)
		drawend = WIN_H - 1;
	j = drawstart;
	while (j <= drawend)
	{
		if (my_mlx_pixel_put(mlx, col, j, color))
			return (perror("vertical line - my pixel put"), 1);
		j++;
	}
	return (0);
}

/*
	camerax convierte la columna j (0..WIN_W) en un valor normalizado [-1,1].
	Esto determina qué parte del plano de visión usa este rayo.

	raydirx/Y = dirección real del rayo en el mundo.
	Es la dirección del jugador + una parte del plano de cámara.

	mapx/Y = celda actual donde está el jugador, convertido a índice entero.

	deltax/Y = cuánto debe avanzar el rayo para cruzar una celda entera en X o Y.
	Si raydir es 0, usamos un número enorme (1e30) para representar “nunca cruzo”.
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
	stepx/Y = hacia qué dirección avanza el rayo en la grilla.

	sidex/Y = distancia desde la posición del jugador hasta la primera pared
	vertical u horizontal que podría cruzar el rayo.

	Si el rayo va hacia la izquierda:
		sidex = (player.x - mapx)
	Si va hacia la derecha:
		sidex = (mapx + 1 - player.x)

	Lo mismo para Y.
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
	sidex ... si va hacia la izquierda
	distancia en X = posición del jugador - X entero de la celda en la que está
	Si va hacia la derecha
	distancia en X	= (X entero de próxima celda) - posición del jugador
               		= (mapx + 1) - jugador.x
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
	Recorro todas las columnas de la pantalla, tirando un rayo por cada una.
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
