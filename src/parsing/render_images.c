/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/14 18:40:38 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*move_line_to_path(char *line, char *id)
{
	ft_printf("checkq\n");
	ft_printf("len:%d\n", ft_strlen(id));
	line = line + 2 ;
	while (ft_isspace(*line) && line++)
	{
	}
	return (line);

}

int	process_params(char *line, t_cub *data, char *id)
{
	line = move_line_to_path(line, id);
	ft_printf("%s", line);
	data->no_texture->full = 1;
	data->no_texture = mlx_xpm_to_image(data->ptr_mlx,\
		&line, &data->img_w, &data->img_h);
	if (!data->no_texture)
	{
		ft_printf("check2\n");
		// s_free(data->no_texture);
		error_texture_path(line, E_NO, data);
		return (1);
	}
	return (0);
}
