/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:02:55 by antuel            #+#    #+#             */
/*   Updated: 2025/12/09 15:58:22 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Parte del algoritmo de Bresenham que itera píxel a píxel.
	Se separó del resto para mantener funciones cortas y claras.
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

/*
	Algoritmo de Bresenham para dibujar líneas en una cuadrícula de píxeles.
	  Implementa el algoritmo de Bresenham para trazar una línea entre dos
  puntos en una malla de píxeles. Pinta cada píxel intermedio con
  my_mlx_pixel_put hasta llegar al punto final.
- Cómo funciona:
  1) Calcula dx y dy como diferencias absolutas entre coordenadas.
  2) Determina los incrementos sx y sy (±1) según la dirección de la línea.
  3) Mantiene un error acumulado (err) que decide si avanzar en x, en y,
     o en ambos, buscando el mejor pixel que aproxime la línea continua.
  4) En cada iteración pinta el pixel actual y ajusta err, x0 o y0 según sea
     necesario hasta que se alcanza el punto destino.
- Notas:
  - No hay variables locales adicionales aparte de la
  	estructura pasada por valor,
    lo que facilita mantener la función corta y simple.
*/
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

/*
  Dibuja una pequeña flecha que representa la posición (punta) y la dirección
  del jugador sobre el mapa: dos líneas que salen de la punta hacia las
  bases izquierda y derecha y una línea que conecta esas dos bases.
- Cómo funciona:
  1) Calcula la posición en píxeles del jugador (px, py) y toma la dirección
     del jugador (dx). El componente dy se usa directamente desde la estructura
     del jugador para evitar declarar más variables.
  2) Calcula las coordenadas de la punta y de las dos bases usando la dirección
     y su vector perpendicular (pdx = -dy, pdy = dx), pero sin declarar pdx/pdy:
     se evalúan las expresiones en línea.
  3) Usa draw_line para trazar:
     - punta -> base izquierda
     - punta -> base derecha
     - base izquierda -> base derecha
- Notas:
  - Se mantiene la geometría original (distancias 15, 8, 5) tal como en el código
    original.
  - Declaración y asignación están separadas para cumplir tu regla.
*/
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
