/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/14 18:42:47 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_map_param(char *line, int fd, t_ecode code)
{

	if (code == E_PARAM)
	{
		ft_printf(CLR_RED"Incorrect id NO: %s\n"RST_ALL, line);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}

	}
	return (0);
}

int	error_texture_path(char *line, t_ecode code, t_cub *data)
{

	if (code == E_NO)
	{
		ft_printf("Error:\nTexture file or directory does not exist\n");
		ft_printf("%s", line);
		mlx_destroy_image(data->ptr_mlx, data->no_texture->id_texture);
		return (1);
	}
	return (0);
}
