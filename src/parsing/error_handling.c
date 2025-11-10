/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/10 11:56:32 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	error_map_param(char *line, int fd, t_ecode code)
{
	if (code == E_PARAM)
	{
		ft_printf(CLR_RED"Incorrect id check: %s\n"RST_ALL, line);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
	}
}

void	error_texture_path(char *line, t_ecode code, char *id, t_cub *data)
{
	if (code == E_texture)
	{
		ft_printf(RST_ALL"Error:\nTexture <%s> not correct\n", id);
		ft_printf(CLR_RED"%s\n"CLR_RED, line);
	}
	if (code == E_color)
	{
		ft_printf(RST_ALL"Error:\nIncorrect <%s> coordinates\n", id);
		ft_printf(CLR_RED"%s\n"CLR_RED, line);
	}
	free_struct(data);
}
