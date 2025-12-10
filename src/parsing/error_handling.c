/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/10 13:59:48 by emurillo         ###   ########.fr       */
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
			s_free(line);
		}
	}
}

void	error_map1(t_ecode code, t_cub *data)
{
	data->dups = 1;
	ft_printf(RST_ALL"Error\n: %s\n", data->map_path);
	if (code == E_NOPLYR)
	{
		ft_printf(CLR_RED"No player in the map\n"RST_ALL);
		ft_printf(CLR_YLLW"[N,S,W,E represent the player]\n"RST_ALL);
	}
	if (code == E_CHARS)
	{
		ft_printf(CLR_RED"Incorrect values in map\n"RST_ALL);
		if (data->ply > 1)
			ft_printf(CLR_RED"Multiple player detected\n");
		ft_printf(CLR_YLLW"[1, 0, ' ', N, S, W, E, are accepted]  "RST_ALL);
		ft_printf(CLR_YLLW"[tabs {\\t} & other chars not accepted]\n"RST_ALL);
	}
	if (code == E_CLOSEDM)
	{
		ft_printf(CLR_RED"Map is not closed correctly\n"RST_ALL);
	}
	if (code == E_MAP)
		ft_printf(CLR_RED"Not closed or invalid format\n"RST_ALL);
	if (code == E_NOMAP)
		ft_printf(CLR_RED"Missing map\n"RST_ALL);
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
	if (code == E_MAP || code == E_NOPLYR || code == E_CHARS
		|| code == E_CLOSEDM || code == E_NOMAP)
		error_map1(code, data);
	if (code == E_NO_ID)
	{
		ft_printf(RST_ALL"Error\n: %s\n", data->map_path);
		ft_printf(CLR_RED"Missing ID in :%s \n"RST_ALL, line);
	}
}
