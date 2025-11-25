/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:37:17 by antuel            #+#    #+#             */
/*   Updated: 2025/11/25 13:14:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_cub *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	// Rotar vector dirección
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_x * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	printf("OLD dir_x: %f\t || \t NEW dir_x: %f\n", old_dir_x, game->player.dir_x);
	// Rotar plano de cámara
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}

/*	chequeo de la colision temporal - aca no tengo en cuenta
	mapas desproporcionados
	si esta entre los limites o si es 1 ... devuelve 1 sino 0

	mas adelante haré el calculo con el pixel siguiente dependiendo
	de la direccion donde mire
	si el pixel siguiente es diferente de 0, hay colision
	*/
// static bool	is_wall(t_cub *game, double x, double y)
// {
// 	printf("Entering with x:%f y:%f\n", x, y);
// 	if (game->map[(int)y][(int)x] == '1' || game->map[(int)y][(int)x] == ' ')
// 		return (true);
// 	return (false);
// }

static void	move_player(t_cub *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + move_x;
	new_y = game->player.y + move_y;
	// if (!is_wall(game, new_x, game->player.y))
	game->player.x = new_x;
	// if (!is_wall(game, new_y, game->player.x))
	game->player.y = new_y;
}

/*   65307 = tecla ESC en X11 --- es decir, cerramos la ventana*/
int	key_press(int keycode, t_cub *game)
{
	if (keycode == 65307)
		close_windows(game);
	if (keycode == KEY_W)
		move_player(game, game->player.dir_x * game->player.mov_speed,
			game->player.mov_speed * game->player.dir_y);
	else if (keycode == KEY_S) // S - Atrás
		move_player(game, -game->player.dir_x * game->player.mov_speed,
			-game->player.dir_y * game->player.mov_speed);
	else if (keycode == KEY_A) // A - Izquierda (strafe)
		move_player(game, game->player.dir_y * game->player.mov_speed,
			game->player.dir_x * game->player.mov_speed);
	else if (keycode == KEY_D) // D - Derecha (strafe)
		move_player(game, -game->player.dir_y * game->player.mov_speed,
			-game->player.dir_x * game->player.mov_speed);
	else if (keycode == KEY_LEFT) // Flecha izquierda - Rotar izquierda
		rotate_player(game, game->player.rot_speed);
	else if (keycode == KEY_RIGHT) // Flecha derecha - Rotar derecha
		rotate_player(game, -game->player.rot_speed);
	draw_map(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	return (0);
}
