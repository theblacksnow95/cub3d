/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:44:04 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/21 14:53:28 by antuel           ###   ########.fr       */
/*                                                                            */
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

t_cub	*init_variables(t_cub *data)
{
	data->no_texture = init_texture(data->no_texture);
	data->so_texture = init_texture(data->so_texture);
	data->we_texture = init_texture(data->we_texture);
	data->ea_texture = init_texture(data->ea_texture);
	data->f_rgb = s_malloc(sizeof(t_rgb));
	data->c_rgb = s_malloc(sizeof(t_rgb));
	data->f_rgb->full = 0;
	data->c_rgb->full = 0;
	data->params_cnt = 0;
	data->fd = 0;
	data->dups = 0;
	data->ply = 0;
	data->mlx.mlx = mlx_init();
	data->mlx.win = NULL;
	data->mlx.img = NULL;
	data->mlx.addr = NULL;
	data->mlx.bpp = 0;
	data->mlx.line_len = 0;
	data->mlx.endian = 0;
	return (data);
}
