/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:37:17 by antuel            #+#    #+#             */
/*   Updated: 2025/12/09 15:57:04 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_cub *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = (game->player.dir_x * cos(rot_speed))
		- (game->player.dir_y * sin(rot_speed));
	game->player.dir_y = (old_dir_x * sin(rot_speed))
		+ (game->player.dir_y * cos(rot_speed));
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}

static void	move_player(t_cub *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + move_x;
	new_y = game->player.y + move_y;
	if (!wall_collition(game, new_x, game->player.y))
		game->player.x = new_x;
	if (!wall_collition(game, game->player.x, new_y))
		game->player.y = new_y;
	return ;
}

void	do_moves(t_cub *game, double move_speed, double rot_speed, t_moves move)
{
	if (move.move_up)
		move_player(game, game->player.dir_x * move_speed,
			move_speed * game->player.dir_y);
	if (move.move_down)
		move_player(game, -game->player.dir_x * move_speed,
			-game->player.dir_y * move_speed);
	if (move.move_left)
		move_player(game, game->player.dir_y * move_speed,
			-game->player.dir_x * move_speed);
	if (move.move_right)
		move_player(game, -game->player.dir_y * move_speed,
			game->player.dir_x * move_speed);
	if (move.rotate_l)
		rotate_player(game, -rot_speed);
	if (move.rotate_r)
		rotate_player(game, rot_speed);
}

/*	65307 = tecla ESC en X11 --- es decir, cerramos la ventana*/
int	movements( t_cub *game)
{
	t_moves	move;
	t_time	t;
	double	move_speed;
	double	rot_speed;

	move = game->moves;
	t = game->tm;
	move_speed = game->player.mov_speed * (t.frame_time / 1000.0) * 0.70;
	rot_speed = game->player.rot_speed * (t.frame_time / 1000.0);
	do_moves(game, move_speed, rot_speed, move);
	return (0);
}
