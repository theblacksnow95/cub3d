/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:36 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/17 09:30:20 by emurillo         ###   ########.fr       */
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

void	colors_processing(char *line, int *var_color, char *id)
{
	char	*tmp;

	line = move_line_to_path(line, id);
	while (*line != '\n')
	{
		if (*line == '(' || *line == ')')
		{
			line++;
			tmp = ft_split(line, ',');
			*var_color= ft_atoi(tmp);
			var_color++;
		}
		line++;
	}
}

void	process_params(char *line, t_cub *data, char *id)
{
	line = move_line_to_path(line, id);
	if (ft_strncmp(id, NO_ID, ft_strlen(id)))
	{
		data->no_texture = mlx_xpm_to_image(data->ptr_mlx, &line, &data->img_w, \
&data->img_h);
		if (!data->no_texture)
			error_texture_path(line, E_NO, data);
	}
}
