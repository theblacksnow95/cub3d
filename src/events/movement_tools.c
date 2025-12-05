/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:11:07 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/05 16:12:33 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*	chequeo de la colision temporal - aca no tengo en cuenta
	mapas desproporcionados
	si esta entre los limites o si es 1 ... devuelve 1 sino 0

	mas adelante haré el calculo con el pixel siguiente dependiendo
	de la direccion donde mire
	si el pixel siguiente es diferente de 0, hay colision
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
