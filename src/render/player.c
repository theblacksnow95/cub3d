/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:12:37 by antuel            #+#    #+#             */
/*   Updated: 2025/12/12 15:13:32 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0.0);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

static void	find_player_position(t_cub *game, int *x, int *y, char *dir)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				*dir = game->map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	init_moves(t_cub *game)
{
	if (!game)
		return ;
	game->moves.move_down = false;
	game->moves.move_left = false;
	game->moves.move_right = false;
	game->moves.move_right = false;
	game->moves.rotate_l = false;
	game->moves.rotate_r = false;
}

void	init_player(t_cub *game)
{
	int		start_x;
	int		start_y;
	char	direction;

	init_moves(game);
	game->tm.old_time = get_time_ms();
	find_player_position(game, &start_x, &start_y, &direction);
	game->player.x = start_x + 0.5;
	game->player.y = start_y + 0.5;
	init_positions(game, direction);
	game->player.mov_speed = 4.1;
	game->player.rot_speed = 3.0;
}
