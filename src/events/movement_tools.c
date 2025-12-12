/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:11:07 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/12 14:58:36 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	wall_collition(t_cub *game, double new_x, double new_y)
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

/*
	chequeo de la colision
*/
bool	is_wall(t_cub *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == ' ')
		return (true);
	return (false);
}

void	open_minimap(t_cub *game)
{
	if (game->mini == false)
		game->mini = true;
	else
		game->mini = false;
}
