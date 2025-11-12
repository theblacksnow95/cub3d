/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map_param(char *line, int fd, t_ecode code)
{
	// int	i;

	// i = 0;
	if (code == E_PARAM)
	{
		ft_printf(CLR_RED"Incorrect id check: %s\n"RST_ALL, line);
		// while (i < 9)
		// {
		// 	line--;
		// 	i++;
		// }
		while (line != NULL)
		{
			line = get_next_line(fd);
			printf("check line after: %s\n", line);
			free(line);
		}
	}
}

void	error_texture_path(char *line, t_ecode code, char *id, t_cub *data)
{
	if (code == E_TEXTURE)
	{
		ft_printf(RST_ALL"Error:\nTexture <%s> not correct\n", id);
		ft_printf(CLR_RED"%s\n"CLR_RED, line);
		data->dups = 1;
	}
	if (code == E_COLOR)
	{
		ft_printf(RST_ALL"Error:\nIncorrect <%s> coordinates\n", id);
		ft_printf(CLR_RED"%s\n"CLR_RED, line);
	}
	// while (data->line)
	// {
	// 	data->line = get_next_line(data->fd);
	// 	printf("check line after: %s\n", data->line);
	// 	s_free(data->line);
	// }
	// error_map_param(data->line, data->fd, E_PARAM);
	printf("check for line: [%s]\n", line);
	// free_struct(data);
	// exit(1);
}
