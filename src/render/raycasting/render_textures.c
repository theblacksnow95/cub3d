/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:26:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/08 12:07:15 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_texture *text, int x, int y)
{
	char	*pixel;

	if (!text ||!text->addr)
		return (0);
	if (x < 0)
		x = 0;
	if (x >= text->text_w)
		x = text->text_w - 1;
	if (y < 0)
		y = 0;
	if (y >= text->text_h)
		y = text->text_h - 1;
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
	// textpos = (game->draws - WIN_H / 2 + game->ray.line_h / 2 )* step;
	while (y <= game->drawe)
	{
		texy = (int)textpos;
		if (texy < 0)
			texy = 0;
		if (texy >= text->text_h)
			texy = text->text_h - 1;	
		textpos += step;
		color = get_color(text, game->ray.tex_x, texy);
		if (game->ray.side == 0)
			color = (color >> 1) & 8355711;
		if (my_mlx_pixel_put(&game->mlx, x, y, color))
			return (1);
		y++;
	}
	return (0);
}

int	put_v_texture(t_cub *game, t_texture *text, int j)
{
	double		wallx;
	double		textpos;

	if (!text || !text->addr)
		return (1);
	if (game->ray.side == 0)
		wallx = game->player.y + (game->ray.perpdist * game->ray.raydiry);
	else
		wallx = game->player.x + (game->ray.perpdist * game->ray.raydirx);
	wallx -= floor(wallx);
	game->ray.tex_x = (int)(wallx * (double)text->text_w);
	if (game->ray.tex_x < 0)
		game->ray.tex_x = 0;
	if (game->ray.tex_x >= text->text_w)
		game->ray.tex_x = text->text_w - 1;
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		game->ray.tex_x = text->text_w - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		game->ray.tex_x = text->text_w - game->ray.tex_x - 1;
	textpos = (game->draws - WIN_H / 2 + game->ray.line_h / 2)
		* ((double)text->text_h / (double)game->ray.line_h);
	return (draw_texture_line(game, text, j, textpos));
}
