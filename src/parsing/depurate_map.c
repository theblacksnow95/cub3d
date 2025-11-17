/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depurate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:31:25 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/17 12:42:41 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(char **map)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (map[i])
		i++;
	map_copy = malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i-- > 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	flood(char **map, int y, int x, t_flood *fill)
{
	if (fill->error == true)
		return;
	if (y < 0 || x < 0 || !map[y]|| !map[y][x])
	{
		fill->error = true;
		return ;
	}
	if (map[y][x] == 'V' || map[y][x] == '1' || map[y][x] == ' ')
		return ;
	map[y][x] = 'V';
	flood(map, y - 1, x, fill);
	flood(map, y + 1, x, fill);
	flood(map, y, x - 1, fill);
	flood(map, y, x + 1, fill);
}

int	map_validation(char **map, int y, int x)
{
	int			i;
	char		**map_copy;
	t_flood		fill;

	i = 0;

	fill.error = false;
	map_copy = copy_map(map);
	if (!map_copy)
		return (1);
	flood(map_copy, y, x, &fill);
	print_array(map_copy);
	printf("fill: [%d]\n", fill.error); //debug
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	return (1);
}

