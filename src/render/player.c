/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:12:37 by antuel            #+#    #+#             */
/*   Updated: 2025/11/17 23:26:03 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_player_position(t_game *game, int *x, int *y, char *dir)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				*dir = game->map[i][j];
				return (0);			
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	init_player(t_game *game)
{
	int		start_x;
	int		start_y;
	char	direction;
	
	if (find_player_position(game, &start_x, &start_y, &direction))
		return (perror("player not found"));
	
	// Posición inicial (centro de la celda + 0.5)
	game->player.x = start_x + 0.5;
	game->player.y = start_y + 0.5;
	
	// Dirección inicial según caracter del mapa
	if (direction == 'N') {
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'S') {
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'E') {
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (direction == 'W') {
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	
	game->player.mov_speed = 0.1;
	game->player.rot_speed = 0.1;
}
