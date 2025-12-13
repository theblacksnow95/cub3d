/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:31:25 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/13 11:20:55 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**copy_map(char **map)
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
				s_free(map_copy[i]);
			s_free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood(char **map, int y, int x, t_flood *fill)
{
	if (fill->error == true)
		return ;
	if (y < 0 || x < 0 || !map[y])
	{
		fill->error = true;
		return ;
	}
	if (x >= (int)ft_strlen(map[y]))
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

int	fill_validation(char **map, int y, int x)
{
	char		**map_copy;
	t_flood		fill;

	fill.error = false;
	map_copy = copy_map(map);
	if (!map_copy)
		return (1);
	flood(map_copy, y, x, &fill);
	print_array(map_copy);
	s_array_free(map_copy);
	if (fill.error)
		return (1);
	return (0);
}
