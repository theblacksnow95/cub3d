/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:13:50 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/08 12:01:46 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_line(char *s)
{
	// if (*s == '\n')
	// 	return (0);
	while (*s != '\n')
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

void	print_array(char **arr)
{
	if (!arr || arr[0][0] == '\0')
		return ;
	while (*arr)
	{
		ft_printf(CLR_BLUE"%s\n"RST_ALL, *arr);
		arr++;
	}
	printf("\n");
}

void	close_read(char *map_str, char *line, t_cub *data, int fd)
{
	printf("trigger close_read()\n");
	error_handler(NULL, E_MAP, EMPTY_ID, data);
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
	while (empty_line(line))
	{
		s_free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

void	read_map(t_cub *data, char *line, int fd)
{
	char	*map_str;
	char	*buf;

	map_str = ft_strdup("");
	line = get_next_line(fd);
	line = advance_to_start(line, fd);
	if (!line)
		close_read(map_str, line, data, fd);
	while (line)
	{
		if (empty_line(line))
			close_read(map_str, line, data, fd);
		buf = map_str;
		map_str = ft_strjoin(map_str, line);
		s_free(line);
		s_free(buf);
		line = get_next_line(fd);
	}
	close(fd);
	data->map = ft_split(map_str, '\n');
	s_free(map_str);
	validate_map(data);
}
