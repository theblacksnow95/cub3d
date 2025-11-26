/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:14:15 by antuel            #+#    #+#             */
/*   Updated: 2025/11/26 15:27:45 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_window(t_mlx *mlx, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			my_mlx_pixel_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

int	draw_player(t_mlx *mlx, double x, double y, int color)
{
	int	i;
	int	j;
	int	radius;

	radius = 5;
	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
			{
				if (my_mlx_pixel_put(mlx, (int)x + j, (int)y + i, color))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
	my_mlx_pixel_put es mejor porque es
	SOLO 1 llamada al sistema para TODOS los píxeles

	desplazamiento de la celda para poner el color:
	dst= mlx->addr + (y * mlx->line_len + x * (mlx->bpp/8));
*/
int	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return (1);
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

/*funcion para dibujar un cuadrado*/
static int	draw_square(t_mlx *mlx, int start_x, int start_y, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < TILE_SIZE)
	{
		if (start_y + y >= WIN_H)
			break ;
		x = 0;
		while (x < TILE_SIZE)
		{
			if (start_x + x >= WIN_W)
				break ;
			if (my_mlx_pixel_put(mlx, start_x + x, start_y + y, color))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
	recorre el mapa pixel por pixel
	dependiendo del valor 0, 1 etc... le agrega el color

	le agrego:
	clear_window(game->mlx.mlx, 0x000000);
	por el momento borro toda la pantalla, talvez mas adelante
	podria borrar solo las posiciones anteriores donde estaba el jugador
*/
int	draw_map(t_cub *game)
{
	int		y;
	int		x;
	int		error;
	char	cell;

	clear_window(game->mlx.mlx, 0x000000);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			cell = game->map[y][x];
			if (cell == '1' || cell == ' ')
				error = draw_square(&game->mlx, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);// blanco
			else
				error = draw_square(&game->mlx, x * TILE_SIZE, y * TILE_SIZE, 0x808080);//gris
			if (error)
				close_windows(game);
			x++;
		}
		y++;
	}
	draw_player(&game->mlx, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE, 0x000FF0);
	return (0);
}
