/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:14:15 by antuel            #+#    #+#             */
/*   Updated: 2025/11/14 23:46:25 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	my_mlx_pixel_put es mejor porque es
	SOLO 1 llamada al sistema para TODOS los píxeles
	
	desplazamiento de la celda para poner el color:
	dst= mlx->addr + (y * mlx->line_len + x * (mlx->bpp/8));
*/
static int my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return (1);
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp/8));
	*(unsigned int*)dst = color;
	return (0);
}

/*funcion para dibujar un cuadrado*/
static int draw_square(t_mlx *mlx, int start_x, int start_y, int color)
{
	int		x;
	int		y;
	
	y = 0;
	while(y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
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
*/
int	draw_map(t_game *game)
{
	int		y;
	int		x;
	int		error;
	char	cell;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			cell = game->map[y][x];
			if  (cell == '1')
				error = draw_square(&game->mlx, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);//rojo
			else if (cell == '0')
				error = draw_square(&game->mlx, x * TILE_SIZE, y * TILE_SIZE, 0x808080);//gris
			else
				error = draw_square(&game->mlx, x * TILE_SIZE, y * TILE_SIZE, 0x00FF00);//verde
			if (error)
				return(perror("error drawing map"), 1);
			x++;
		}
		y++;
	}
	return (0);
}