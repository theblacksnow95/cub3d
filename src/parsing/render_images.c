/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/05 17:12:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*move_line_to_path(char *line, char *id)
{
	// ft_printf("check\n");
	// ft_printf("len:%d\n", ft_strlen(id));
	line = line + (int)ft_strlen(id);
	while (ft_isspace(*line) && line++)
	{
	}
	return (line);
}

void	colors_f_c(char *line, t_cub *data, char *id)
{
	printf("here!!\n");
	line = move_line_to_path(line, id);
	colors_rgb(line, id, data);
}

void	process_params(char *line, t_cub *data, char *id)
{
	line = move_line_to_path(line, id);
	if (ft_strncmp(id, NO_ID, ft_strlen(id)))
		data->no_texture->id_texture = mlx_xpm_to_image
			(data->ptr_mlx, &line, &data->img_w, &data->img_h);
	if (ft_strncmp(id, SO_ID, ft_strlen(id)))
		data->so_texture->id_texture = mlx_xpm_to_image
			(data->ptr_mlx, &line, &data->img_w, &data->img_h);
	if (ft_strncmp(id, WE_ID, ft_strlen(id)))
		data->we_texture->id_texture = mlx_xpm_to_image
			(data->ptr_mlx, &line, &data->img_w, &data->img_h);
	if (ft_strncmp(id, EA_ID, ft_strlen(id)))
		data->ea_texture->id_texture = mlx_xpm_to_image
			(data->ptr_mlx, &line, &data->img_w, &data->img_h);
	else if (!data->no_texture->id_texture || !data->so_texture->id_texture
		|| !data->we_texture->id_texture || !data->ea_texture->id_texture)
		error_texture_path(line, E_texture, id, data);
}
