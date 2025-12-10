/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:13:50 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/10 13:58:22 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	empty_newline(char *s)
{
	while (*s != '\n')
	{
		if (*s != '\n')
			return (0);
		s++;
	}
	return (1);
}

void	close_read(char *map_str, char *line, t_cub *data, int fd)
{
	ft_printf("trigger close_read()\n");
	if (!line)
		error_handler(NULL, E_NOMAP, EMPTY_ID, data);
	else
		error_handler(NULL, E_MAP, EMPTY_ID, data);
	ft_printf(CLR_YLLW"Possible invalid chars or data\n"RST_ALL);
	s_free(map_str);
	s_free(line);
	while (line)
	{
		line = get_next_line(fd);
		s_free(line);
	}
	close_windows(data);
}

char	*advance_to_start(char *line, int fd)
{
	if (!line)
		return (NULL);
	while (empty_line(line))
	{
		s_free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

void	read_loop(t_cub *data, char *line, int fd, char **map_str)
{
	char	*buf;

	while (line)
	{
		if (empty_newline(line))
		{
			if (!data->end)
				data->end = true;
			s_free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (data->end)
			close_read(*map_str, line, data, fd);
		buf = *map_str;
		*map_str = ft_strjoin(*map_str, line);
		s_free(buf);
		s_free(line);
		line = get_next_line(fd);
	}
}

void	read_map(t_cub *data, char *line, int fd)
{
	char	*map_str;

	map_str = ft_strdup("");
	line = get_next_line(fd);
	if (!line)
		close_read(map_str, line, data, fd);
	line = advance_to_start(line, fd);
	if (!line)
		close_read(map_str, line, data, fd);
	data->end = false;
	if (!line)
		close_read(map_str, line, data, fd);
	read_loop(data, line, fd, &map_str);
	close(fd);
	data->map = ft_split(map_str, '\n');
	s_free(map_str);
	validate_map(data);
}
