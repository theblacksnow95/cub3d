/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:32 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/01 23:13:16 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Dibuja una línea vertical desde drawStart a drawEnd en X = column */
static void draw_vertical_line(t_mlx *mlx, int column, int drawStart, int drawEnd, int color)
{
    if (column < 0 || column >= WIN_W) return;
    if (drawStart < 0) drawStart = 0;
    if (drawEnd >= WIN_H) drawEnd = WIN_H - 1;
    for (int y = drawStart; y <= drawEnd; y++)
        my_mlx_pixel_put(mlx, column, y, color);
}

/* Esqueleto básico de DDA raycasting, sin texturas */
void cast_all_rays(t_cub *game)
{
    for (int x = 0; x < WIN_W; x++) {
        double cameraX = 2.0 * x / (double)WIN_W - 1.0;
        double rayDirX = game->player.dir_x + game->player.plane_x * cameraX;
        double rayDirY = game->player.dir_y + game->player.plane_y * cameraX;

        int mapX = (int)game->player.x;
        int mapY = (int)game->player.y;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);

        int stepX, stepY;
        double sideDistX, sideDistY;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (game->player.x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->player.x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (game->player.y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->player.y) * deltaDistY;
        }

        int hit = 0;
        int side = 0; // 0: X, 1: Y

        // DDA
        while (!hit) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            char cell = game->map[mapY][mapX];
            if (cell == '1' || cell == ' ') hit = 1;
        }

        // Distancia perpendicular para evitar fisheye
        double perpWallDist;
        if (side == 0)
            perpWallDist = (sideDistX - deltaDistX);
        else
            perpWallDist = (sideDistY - deltaDistY);

        // Altura de la línea en pantalla
        int lineHeight = (int)(WIN_H / (perpWallDist > 1e-6 ? perpWallDist : 1e-6));
        int drawStart = -lineHeight / 2 + WIN_H / 2;
        int drawEnd = lineHeight / 2 + WIN_H / 2;

        // Color simple (oscurecer si side == 1)
        int color = (side == 1) ? 0x009900 : 0x00CC00;
        draw_vertical_line(&game->mlx, x, drawStart, drawEnd, color);
    }
}
