/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   init_var.c :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: antuel <antuel@student.42.fr>  +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2025/10/14 18:44:04 by emurillo  #+##+# */
/*   Updated: 2025/11/23 19:16:15 by antuel   ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*init_texture(t_texture *t)
{
	t_texture	*texture;

	texture = s_malloc(sizeof(t_texture));
	t = texture;
	t->full = 0;
	t->id_texture = 0;
	return (t);
}

void	init_flags(t_cub *data)
{
	data->params_cnt = 0;
	data->fd = -1;
	data->dups = 0;
	data->ply = 0;
	data->mlx.win = NULL;
	data->mlx.img = NULL;
	data->mlx.addr = NULL;
	data->mlx.bpp = 0;
	data->mlx.line_len = 0;
	data->mlx.endian = 0;
	data->dark = false;
}

t_cub	*init_variables(t_cub *data)
{
	ft_bzero(data, sizeof(t_cub));
	data->no_texture = s_malloc(sizeof(t_texture));
	data->so_texture = s_malloc(sizeof(t_texture));
	data->we_texture = s_malloc(sizeof(t_texture));
	data->ea_texture = s_malloc(sizeof(t_texture));
	data->f_rgb = s_malloc(sizeof(t_rgb));
	data->c_rgb = s_malloc(sizeof(t_rgb));
	ft_bzero(data->no_texture, sizeof(t_texture));
	ft_bzero(data->so_texture, sizeof(t_texture));
	ft_bzero(data->we_texture, sizeof(t_texture));
	ft_bzero(data->ea_texture, sizeof(t_texture));
	ft_bzero(data->f_rgb, sizeof(t_rgb));
	ft_bzero(data->c_rgb, sizeof(t_rgb));
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (NULL);
	init_flags(data);
	return (data);
}
