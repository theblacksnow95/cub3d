/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/10 11:54:49 by emurillo         ###   ########.fr       */
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
	// printf("here!!\n");
	line = move_line_to_path(line, id);
	colors_rgb(line, id, data);
}

static void	render_image(t_cub *data, char *line, char *id, t_texture *t)
{

	printf("line: [%s]\n", line); // debug
	t->id_texture = mlx_xpm_file_to_image
		(data->ptr_mlx, line, &data->img_w, &data->img_h);
	if (!t->id_texture || t->full)
	{
		printf(CLR_YLLW"error triggered in f'(render_image)\n"RST_ALL); //debug
		error_texture_path(line, E_texture, id, data);
	}
	t->full = 1;
	printf("Img Id <%s> full: [%d]\n", id, t->full); // debug
	printf("img: %p\n", t->id_texture); //debug
}

// cambiar la funcion render para pasar la estructura texture y que la tome como un argumento
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
