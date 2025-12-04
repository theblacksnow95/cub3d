/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:26:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/04 15:38:09 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture *select_texture(t_cub *game)
{
	t_texture *text;

	if (game->ray.side == 0)
	{
		if (game->ray.rayDir_x > 0)
			text = game->we_texture;
		else
			text = game->ea_texture;
	}
	else
	{
		if (game->ray.rayDir_y > 0)
			text = game->no_texture;
		else
			text = game->so_texture;
	}

}

void	render_textures(t_cub *game, t_player *player, double start, double end)
{
	t_texture *text;
	double	wallX;
	double	textX;
	text = select_texture(game);
	if (game->ray.side == 0)
		wallX = game->player.y + (game->ray.perpwalldist * game->ray.rayDir_y);
	else 
		wallX = game->player.x + (game->ray.perpwalldist * game->ray.rayDir_y);
	wallX = -floor(wallX);
	textX = (int)wallX * (double)text->text_w;
	if (game->ray.side == 0 && game->ray.rayDir_x > 0)
		textX = text->text_w - textX - 1;
	if (game->ray.side == 1 && game->ray.rayDir_y < 0)
		textX = text->text_w - textX - 1;
}
