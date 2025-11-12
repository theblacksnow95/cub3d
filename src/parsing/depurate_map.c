/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depurate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:31:25 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/12 22:36:23 by emurillo         ###   ########.fr       */
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

void	flood(char **map, int y, int x, t_flood *state)
{
	if (y < 0 || x < 0 || map[y][x] == '\0' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E' )
	{
		state->exit_reached = 1;
		return ;
	}
	map[y][x] = 'V';
	flood(map, y - 1, x, state);
	flood(map, y + 1, x, state);
	flood(map, y, x - 1, state);
	flood(map, y, x + 1, state);
}

int	map_validation(char **map, int y, int x, int coins)
{
	int			i;
	char		**map_copy;
	t_flood		state;

	i = 0;
	state.collected = 0;
	state.exit_reached = 0;
	state.total_collectibles = coins;
	map_copy = copy_map(map);
	if (!map_copy)
		exit(1);
	flood(map_copy, y, x, &state);
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (state.collected != state.total_collectibles)
		return (0);
	if (!state.exit_reached)
		return (0);
	return (1);
}

