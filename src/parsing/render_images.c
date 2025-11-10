/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/08 23:02:09 by emurillo         ###   ########.fr       */
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

static void *render_image(t_cub *data, char *line, char *id, t_texture t)
{
	void *image;

	printf("line: [%s]\n", line); // debug
	image = mlx_xpm_file_to_image
	(data->ptr_mlx, line, &data->img_w, &data->img_h);
	if (!image)
	{
		printf(CLR_YLLW"error triggered in f'(render_image)\n"RST_ALL); //debug
		error_texture_path(line, E_texture, id, data);
	}
	printf("img: %p\n", image); //debug
	return (image);
}

int	is_full(t_texture *texture)
{
	if (texture->full == 0)
		return (0);
	return (1);
}

// cambiar la funcion render para pasar la estructura texture y que la tome como un argumento
void	process_params(char *line, t_cub *data, char *id)
{
	line = move_line_to_path(line, id);
	if (!ft_strncmp(id, NO_ID, ft_strlen(id)))
		data->no_texture->id_texture = render_image(data, line, id);
	if (!ft_strncmp(id, SO_ID, ft_strlen(id)))
		data->so_texture->id_texture = render_image(data, line, id);
	if (!ft_strncmp(id, WE_ID, ft_strlen(id)))
		data->we_texture->id_texture = render_image(data, line, id);
	if (!ft_strncmp(id, EA_ID, ft_strlen(id)))
		data->ea_texture->id_texture = render_image(data, line, id);
}
