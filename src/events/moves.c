/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:53:46 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/09 15:57:47 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_cub *game)
{
	if (KEY_W == keycode || KEY_UP == keycode)
		game->moves.move_up = false;
	if (KEY_S == keycode || KEY_DOWN == keycode)
		game->moves.move_down = false;
	if (KEY_A == keycode)
		game->moves.move_left = false;
	if (KEY_D == keycode)
		game->moves.move_right = false;
	if (KEY_LEFT == keycode)
		game->moves.rotate_l = false;
	if (KEY_RIGHT == keycode)
		game->moves.rotate_r = false;
	return (0);
}

int	key_press(int keycode, t_cub *game)
{
	if (keycode == KEY_ESC)
		close_windows(game);
	if (keycode == KEY_M)
		open_minimap(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		game->moves.move_up = true;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->moves.move_down = true;
	if (keycode == KEY_A)
		game->moves.move_left = true;
	if (keycode == KEY_D)
		game->moves.move_right = true;
	if (keycode == KEY_LEFT)
		game->moves.rotate_l = true;
	else if (keycode == KEY_RIGHT)
		game->moves.rotate_r = true;
	return (0);
}
