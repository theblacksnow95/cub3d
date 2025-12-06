/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:26:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/06 17:19:27 by emurillo         ###   ########.fr       */
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

int	compute_wallx(t_cub *game, t_ray *ray, t_texture *t)
{
	double		wallx;
	double		textx;

	if (ray->side == 0)
		wallx = game->player.y + (ray->perpdist * ray->raydiry);
	else
		wallx = game->player.x + (ray->perpdist * ray->raydiry);
	wallx = -floor(wallx);
	textx = (int)wallx * (double)t->text_w;
	if (ray->side == 0 && ray->raydirx > 0)
		textx = t->text_w - textx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		textx = t->text_w - textx - 1;
	return (textx);
}

int	put_v_texture(t_cub *game, t_texture *text, int j)
{
	
}
