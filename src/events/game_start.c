/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:37:17 by antuel            #+#    #+#             */
/*   Updated: 2025/12/07 13:26:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_cub *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	// Rotar vector dirección
	old_dir_x = game->player.dir_x;
	game->player.dir_x = (game->player.dir_x * cos(rot_speed))
		- (game->player.dir_y * sin(rot_speed));
	game->player.dir_y = (old_dir_x * sin(rot_speed))
		+ (game->player.dir_y * cos(rot_speed));
	// Rotar plano de cámara
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}



static bool	wall_collition(t_cub *game, double new_x, double new_y)
{
	double	r;

	r = COLLITION_RAD;
	if (is_wall(game, new_x + r, new_y))
		return (true);
	if (is_wall(game, new_x - r, new_y))
		return (true);
	if (is_wall(game, new_x, new_y + r))
		return (true);
	if (is_wall(game, new_x, new_y - r))
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
	if (keycode == KEY_M)
		open_minimap(game);
	if (keycode == KEY_W)
		move_player(game, game->player.dir_x * game->player.mov_speed,
			game->player.mov_speed * game->player.dir_y);
	else if (keycode == KEY_S)
		move_player(game, -game->player.dir_x * game->player.mov_speed,
			-game->player.dir_y * game->player.mov_speed);
	else if (keycode == KEY_A)
		move_player(game, game->player.dir_y * game->player.mov_speed,
			-game->player.dir_x * game->player.mov_speed);
	else if (keycode == KEY_D)
		move_player(game, -game->player.dir_y * game->player.mov_speed,
			game->player.dir_x * game->player.mov_speed);
	else if (keycode == KEY_LEFT)
		rotate_player(game, -game->player.rot_speed);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, game->player.rot_speed);
	game_loop(game);
	return (0);
}
