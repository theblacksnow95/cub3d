/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/13 15:57:39 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_params(char *line, t_cub *data, char * id)
{
	if (ft_strncmp(id, NO_ID, ft_strlen(id)))
	{
		data->no_texture = mlx_xpm_to_image(data->ptr_mlx, &line, &data->img_w,\
			&data->img_h);
		if (!data->no_texture)	
			error_texture_path(line, E_NO);
	}
	return (0);
}
