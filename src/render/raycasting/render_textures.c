/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:26:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/06 18:06:25 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	get_color(t_texture *text, int x, int y)
{
	char	*pixel;

	pixel = text->addr + (y * text->line_len + x * (text->bpp / 8));
	return (*(unsigned int *)pixel);
}

int	draw_texture_line(t_cub *game, t_texture *text, int x, double textpos)
{
	int		y;
	int		texy;
	double	step;
	int		color;

	y = game->draws;
	step = (double)text->text_h / (double)game->ray.line_h;
	while (y < game->draws)
	{
		texy = (int)textpos & (text->text_h - 1);
		textpos += step;
		color = get_color(text, game->ray.tex_x, texy);
		if (my_mlx_pixel_put(game->mlx.mlx, x, y, color))
			return (1);
		y++;
	}
	return (0);
}

int	put_v_texture(t_cub *game, t_texture *text, int j)
{
	double		wallx;
	double		textx;
	double		textpos;

	if (game->ray.side == 0)
		wallx = game->player.y + (game->ray.perpdist * game->ray.raydiry);
	else
		wallx = game->player.x + (game->ray.perpdist * game->ray.raydiry);
	wallx = -floor(wallx);
	textx = (int)wallx * (double)text->text_w;
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		textx = text->text_w - textx - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		textx = text->text_w - textx - 1;
	textpos = (game->draws - WIN_H / 2 + game->ray.line_h / 2)
		* ((double)text->text_h / (double)game->ray.line_h);
	return (draw_texture_line(game, text, j, textpos));
}
