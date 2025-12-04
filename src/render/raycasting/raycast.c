/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:32 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/04 23:34:39 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int draw_vertical_line( t_mlx *mlx, int col, int drawstart, int drawend, int color)
{
	int j;

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
	cameraX convierte la columna j (0..WIN_W) en un valor normalizado [-1,1].
	Esto determina qué parte del plano de visión usa este rayo.

	raydirX/Y = dirección real del rayo en el mundo.
	Es la dirección del jugador + una parte del plano de cámara.

	mapX/Y = celda actual donde está el jugador, convertido a índice entero.

	deltaX/Y = cuánto debe avanzar el rayo para cruzar una celda entera en X o Y.
	Si raydir es 0, usamos un número enorme (1e30) para representar “nunca cruzo”.
*/
static void	ray_init(t_cub *game, t_ray *ray, int j)
{
	ray->cameraX = 2.0 * j / (double)WIN_W - 1.0;
	ray->raydirX = game->player.dir_x + game->player.plane_x * ray->cameraX;
	ray->raydirY = game->player.dir_y + game->player.plane_y * ray->cameraX;
	ray->mapX = (int)game->player.x;
	ray->mapY = (int)game->player.y;
	if (ray->raydirX == 0.0)
		ray->deltaX = 1e30;
	else
		ray->deltaX = fabs(1.0 / ray->raydirX);
	if (ray->raydirY == 0.0)
		ray->deltaY = 1e30;
	else
		ray->deltaY = fabs(1.0 / ray->raydirY);
}


/*
	stepX/Y = hacia qué dirección avanza el rayo en la grilla.

	sideX/Y = distancia desde la posición del jugador hasta la primera pared
	vertical u horizontal que podría cruzar el rayo.

	Si el rayo va hacia la izquierda:
		sideX = (player.x - mapX)
	Si va hacia la derecha:
		sideX = (mapX + 1 - player.x)

	Lo mismo para Y.
*/
static void	ray_step_init(t_cub *game, t_ray *ray)
{
	if (ray->raydirX < 0.0)
	{
		ray->stepX = -1;
		ray->sideX = (game->player.x - ray->mapX) * ray->deltaX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideX = (ray->mapX + 1.0 - game->player.x) * ray->deltaX;
	}
	if (ray->raydirY < 0.0)
	{
		ray->stepY = -1;
		ray->sideY = (game->player.y - ray->mapY) * ray->deltaY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideY = (ray->mapY + 1.0 - game->player.y) * ray->deltaY;
	}
}

/*
	sidex ... si va hacia la izquierda
	distancia en X = posición del jugador - X entero de la celda en la que está
	Si va hacia la derecha
	distancia en X	= (X entero de próxima celda) - posición del jugador
               		= (mapX + 1) - jugador.x
*/
static int	cast_single_ray(t_cub *game, int j)
{
	t_ray	ray;
	double	perpdist;
	int		lineh;
	int		draws;
	int		drawe;
	int		color;

	ray_init(game, &ray, j);
	ray_step_init(game, &ray);
	while (1)
	{
		if (ray.sideX < ray.sideY)
		{
			ray.sideX += ray.deltaX;
			ray.mapX += ray.stepX;
			ray.side = 0;
		}
		else
		{
			ray.sideY += ray.deltaY;
			ray.mapY += ray.stepY;
			ray.side = 1;
		}
		if (game->map[ray.mapY][ray.mapX] == '1')
			break ;
	}
	if (ray.side == 0)
		perpdist = (ray.sideX - ray.deltaX);
	else
		perpdist = (ray.sideY - ray.deltaY);
	lineh = (int)(WIN_H / perpdist);
	draws = -lineh / 2 + WIN_H / 2;
	drawe = lineh / 2 + WIN_H / 2;
	if (ray.side == 0)
		color = 0xFF0000;	// 🔴 paredes verticales (N/S)
	else
		color = 0x0000FF;	// 🔵 paredes horizontales (E/O)
	return (draw_vertical_line(&game->mlx, j, draws, drawe, color));
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
