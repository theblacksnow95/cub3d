/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/14 16:19:29 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*move_line_to_path(char *line, char *id)
{
	ft_printf("checkq\n");
	ft_printf("len:%d\n", ft_strlen(id));
	if (ft_strncmp(id, line, (size_t)ft_strlen(id)))
	{
		ft_printf("check");
		line = line + ft_strlen(id);
	}
	while (ft_isspace(*line))
	{
		line++;
	}
	return (line);

}

int	process_params(char *line, t_cub *data, char *id)
{
	line = (char *)move_line_to_path(line, id);
	ft_printf("%s", line);
	if (ft_strncmp(id, NO_ID, 2))
	{
		ft_printf("enter image charge\n");
		data->no_texture = mlx_xpm_to_image(data->ptr_mlx, &line, &data->img_w,\
			&data->img_h);
		if (data->no_texture == NULL)
			error_texture_path(line, E_NO);
	}
	return (0);
}
