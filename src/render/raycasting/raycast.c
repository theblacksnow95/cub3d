/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:32 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/04 23:01:52 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int draw_vertical_line(t_mlx *mlx, int col, int drawstart, int drawend,
	t_texture *tex, int texX, int lineHeight)
{
	int	j;
	int	texY;
	int	color;
	int	d;

	if (col < 0 || col >= WIN_W)
		return (perror("printing vertical line"), 1);
	if (drawstart < 0)
		drawstart = 0;
	if (drawend >= WIN_H)
		drawend = WIN_H - 1;
	j = drawstart;
	while (j <= drawend)
	{
		d = j * 256 - WIN_H * 128 + lineHeight * 128;
		texY = ((d * tex->height) / lineHeight) / 256;
		texY = (texY < 0) ? 0 : ((texY >= tex->height) ? tex->height - 1 : texY);
		color = tex->rendered[tex->width * texY + texX];
		if (my_mlx_pixel_put(mlx, col, j, color))
			return (perror("vertical line - my pixel put"), 1);
		j++;
	}
	return (0);
}

/*
	ray->cameraX = 2.0 * j / (double)WIN_W - 1.0;
	ray->raydirX = game->player.dir_x + game->player.plane_x * ray->cameraX;
	ray->raydirY = game->player.dir_y + game->player.plane_y * ray->cameraX;	
	Convierte la columna de pantalla (j) en una coordenada normalizada que
	va de -1 a +1. En otras palabras, para saber a donde apunta para poder
	imprimir bien la columna
	
	cameraX: posicion normalizada en pantalla [-1, 1] para la columna j.

	raydirX/Y: dirección del rayo en el mundo (dir + plane * cameraX).

	mapX/Y: celda inicial del jugador (índice entero).

	deltaX/Y: cuánto "costo" (distancia) recorre el rayo para cruzar una
	celda en X/Y. Si dir es 0 usamos 1e30 para evitar división por cero..

	deltaX es la distancia que recorre el rayo para cruzar una celda en X,
	Si raydirX es cero, no importa cuánto sumes, nunca cruzarás una pared en
	X, entonces poner un número gigantesco (1e30) significa: “prácticamente
	nunca cruzo X, siempre cruzo Y primero”.
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
static t_texture	*select_texture(t_cub *game, t_ray *ray)
{
	if (ray->side == 0 && ray->raydirX > 0)
		return (game->ea_texture);
	else if (ray->side == 0)
		return (game->we_texture);
	else if (ray->side == 1 && ray->raydirY > 0)
		return (game->so_texture);
	else
		return (game->no_texture);
}

static int	cast_single_ray(t_cub *game, int j)
{
	t_ray		ray;
	double		perpdist;
	int			lineh;
	int			draws;
	int			drawe;
	double		wallX;
	int			texX;
	t_texture	*tex;

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
		wallX = game->player.y + perpdist * ray.raydirY;
	else
		wallX = game->player.x + perpdist * ray.raydirX;
	wallX -= floor(wallX);
	tex = select_texture(game, &ray);
	texX = (int)(wallX * (double)tex->width);
	if ((ray.side == 0 && ray.raydirX > 0)
		|| (ray.side == 1 && ray.raydirY < 0))
		texX = tex->width - texX - 1;
	texX = (texX < 0) ? 0 : ((texX >= tex->width) ? tex->width - 1 : texX);
	return (draw_vertical_line(&game->mlx, j, draws, drawe, tex, texX, lineh));
}

/*
	recorro todas las columnas
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
