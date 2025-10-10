/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/10 14:58:54 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_map_param(char *line, int fd, t_ecode code)
{

	if (code == E_PARAM)
	{
		ft_printf(CLR_RED"Incorrect id NO: %s\n"RST_ALL, line);
		while(line)
		{
			free(line);
			line = get_next_line(fd);
		}

	}
	return (0);
}

int	error_texture_path(char *line, t_cub *data, t_ecode code)
{
	(void *)data;
	if (code == E_NO)
	{
		ft_printf("Error:\nTexture file or directory does not exist\n");
		return (1);
	}
}
