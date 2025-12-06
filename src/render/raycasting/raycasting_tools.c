/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:06:59 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/06 17:07:18 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*select_texture(t_cub *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydirx > 0)
			return (game->we_texture);
		else
			return (game->ea_texture);
	}
	else
	{
		if (ray->raydiry > 0)
			return (game->no_texture);
		else
			return (game->so_texture);
	}
}



void	dda(t_cub *game, t_ray ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray.sidex < ray.sidey)
		{
			ray.sidex += ray.deltax;
			ray.mapx += ray.stepx;
			ray.side = 0;
		}
		else
		{
			ray.sidey += ray.deltay;
			ray.mapy += ray.stepy;
			ray.side = 1;
		}
		if (game->map[ray.mapy][ray.mapx] == '1'
			|| game->map[ray.mapy][ray.mapx] == ' ' )
			hit = 1;
	}
}
