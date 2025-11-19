/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:13:50 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/19 18:26:12 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_line(char *s)
{
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
	// if (buf)
	// 	free(buf);
	free_struct(data);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	exit(1);
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
		free(line);
		free(buf);
		line = get_next_line(fd);
	}
	close(fd);
	data->map = ft_split(map_str, '\n');
	free(map_str);
	// print_array(data->map); // debug
	// add a link to flood fill
	validate_map(data);
	// map_validation(data->map, data->y_p, data->x_p);
}
