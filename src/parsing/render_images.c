/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/09 15:53:10 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*move_line_to_path(char *line, char *id)
{
	int	i;

	i = 0;
	line = line + (int)ft_strlen(id);
	while (ft_isspace(*line) && line++)
	{
	}
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}

void	colors_f_c(char *line, t_cub *data, char *id)
{
	line = move_line_to_path(line, id);
	colors_rgb(line, id, data);
}

static void	render_image(t_cub *data, char *line, char *id, t_texture *t)
{
	int	w;
	int	h;

	if (!t->id_texture || !t->full)
		t->id_texture = mlx_xpm_file_to_image
			(data->mlx.mlx, line, &w, &h);
	if (!t->id_texture || t->full)
	{
		printf(CLR_YLLW"error triggered in f'(render_image)\n"RST_ALL);
		error_handler(line, E_TEXTURE, id, data);
		data->dups = 1;
	}
	if (t->id_texture)
	{
		t->full = 1;
		t->addr = mlx_get_data_addr
			(t->id_texture, &t->bpp, &t->line_len, &t->endian);
		t->text_w = w;
		t->text_h = h;
	}
	printf(CLR_BLUE"Img Id <%s> full: [%d]\n"RST_ALL, id, t->full);
}

void	process_params(char *line, t_cub *data, char *id)
{
	line = move_line_to_path(line, id);
	if (!ft_strncmp(id, NO_ID, ft_strlen(id)))
		render_image(data, line, id, data->no_texture);
	if (!ft_strncmp(id, SO_ID, ft_strlen(id)))
		render_image(data, line, id, data->so_texture);
	if (!ft_strncmp(id, WE_ID, ft_strlen(id)))
		render_image(data, line, id, data->we_texture);
	if (!ft_strncmp(id, EA_ID, ft_strlen(id)))
		render_image(data, line, id, data->ea_texture);
}
