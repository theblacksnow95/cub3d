/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:37:17 by antuel            #+#    #+#             */
/*   Updated: 2025/11/27 15:57:00 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_cub *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	// Rotar vector dirección
	printf("OLD dirX: %f\n", game->player.dir_x);
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	printf("NEW dir_x: %f", game->player.dir_x);
	printf("\t NEW dir_y: %f\n", game->player.dir_y);
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
static bool	is_wall(t_cub *game, double x, double y)
{	
	int	map_x;
	int	map_y;
	map_x = (int)x;
	map_y = (int)y;
	if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == ' ')
			return (true);
	return (false);
}

static bool wall_collition(t_cub *game, double new_x, double new_y)
{
	double r;

	r = COLLITION_RAD;
	if (is_wall(game, new_x + r, new_y))
		return (true);
	if (is_wall(game, new_x - r, new_y))
		return (true);
	if (is_wall(game, new_x , new_y + r))
		return (true);
	if (is_wall(game, new_x , new_y - r))
		return (true);
	if (is_wall(game, new_x + r, new_y + r))
		return (true);
	if (is_wall(game, new_x + r, new_y - r))
		return (true);
	if (is_wall(game, new_x - r, new_y - r))
		return (true);
	if (is_wall(game, new_x - r, new_y + r))
		return (true);
	return (false);
}

static void	move_player(t_cub *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player.x + move_x;
	new_y = game->player.y + move_y;
	// printf("player pos: y=%f, x=%f\n", gamze->player.y, game->player.x);
	if (!wall_collition(game, new_x, game->player.y))
		game->player.x = new_x;
	if (!wall_collition(game, game->player.x, new_y))
		game->player.y = new_y;
	return ;
}

/*   65307 = tecla ESC en X11 --- es decir, cerramos la ventana*/
int	key_press(int keycode, t_cub *game)
{
	if (keycode == 65307)
		close_windows(game);
	draw_player(&game->mlx, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE, 0x808080);
	if (keycode == KEY_W)
		move_player(game, game->player.dir_x * game->player.mov_speed,
			game->player.mov_speed * game->player.dir_y);
	else if (keycode == KEY_S) // S - Atrás
		move_player(game, -game->player.dir_x * game->player.mov_speed,
			-game->player.dir_y * game->player.mov_speed);			
	else if (keycode == KEY_A) // A - Izquierda (strafe)
		move_player(game, game->player.dir_y * game->player.mov_speed,
			-game->player.dir_x * game->player.mov_speed);
	else if (keycode == KEY_D) // D - Derecha (strafe)
		move_player(game, -game->player.dir_y * game->player.mov_speed ,
			game->player.dir_x * game->player.mov_speed);
	else if (keycode == KEY_LEFT) // Flecha izquierda - Rotar izquierda
		rotate_player(game, -game->player.rot_speed);
	else if (keycode == KEY_RIGHT) // Flecha derecha - Rotar derecha
		rotate_player(game, game->player.rot_speed);

	draw_player(&game->mlx, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE, 0x000FF0);
	// draw_map(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 100, 0);
	return (0);
}
