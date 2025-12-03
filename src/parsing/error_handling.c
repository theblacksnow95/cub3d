/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/03 14:16:16 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map_param(char *line, int fd, t_ecode code)
{

	if (code == E_PARAM)
	{
		ft_printf(CLR_RED"Incorrect id check: %s\n"RST_ALL, line);
		while (line != NULL)
		{
			line = get_next_line(fd);
			printf("check line after: %s\n", line);
			free(line);
		}
	}
}

void	error_handler(char *line, t_ecode code, char *id, t_cub *data)
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
		data->dups = 1;
	}
	if (code == E_MAP)
	{
		ft_printf(RST_ALL"Error\n: %s\n", data->map_path);
		ft_printf(CLR_RED"Incorrect map\n"RST_ALL);
	}
	if (code == E_NO_ID)
	{
		ft_printf(RST_ALL"Error\n: %s\n", data->map_path);
		ft_printf(CLR_RED"Missing ID in :%s \n"RST_ALL, line);
	}
}
