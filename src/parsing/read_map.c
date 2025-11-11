/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:13:50 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/11 15:19:40 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_array(char **arr)
{
	if (!arr || arr[0][0] == '\0')
		return ;
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
	printf("\n");
}

void	close_read(char *map_str, char *line, t_cub *data, int	fd)
{
	ft_printf("Error\n Map not valid.\n");
	free(map_str);
	free(line);
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
	while (*line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

char	**read_map(t_cub *data, char *line, int fd)
{
	char	*map_str;
	char	*buf;

	map_str = ft_strdup("");
	line = get_next_line(fd);
	line = advance_to_start(line, fd);
	while (line)
	{
		if (line[0] == '\n')
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
	print_array(data->map);
	return (data->map);
}
