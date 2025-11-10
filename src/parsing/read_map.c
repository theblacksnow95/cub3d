/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:13:50 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/10 15:35:26 by emurillo         ###   ########.fr       */
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
}

void	close_read(char *map_str, char *line, char *buf)
{
	ft_printf("Error\n Map not valid.\n");
	free(map_str);
	free(line);
	free(buf);
}

char	**read_map(t_cub *data, char *line, int fd)
{
	char	*map_str;
	char	*buf;

	map_str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			close_read(map_str, line, buf);
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
