/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:12:37 by antuel            #+#    #+#             */
/*   Updated: 2025/12/01 13:26:18 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*FUNCION PARA BUSCAR LA POSICION INICIAL DEL JUGADOR EN EL MAPA Y
	ASIGNARLA A LA ESTRUCTURA PLAYER DEL JUEGO*/
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
void	init_positions(t_cub *game, char direction)
{
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
}


void	init_player(t_cub *game)
{
	int		start_x;
	int		start_y;
	char	direction;

	find_player_position(game, &start_x, &start_y, &direction);
	game->player.x = start_x + 0.5;
	game->player.y = start_y + 0.5;
	// Dirección inicial según caracter del mapa
	init_positions(game, direction);
	game->player.mov_speed = 0.1;
	game->player.rot_speed = 0.2;
}
