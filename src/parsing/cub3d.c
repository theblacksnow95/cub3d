/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/02 14:26:45 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int ac, char **av)
{
	char	*map_path;

	if (ac != 2)
	{
		(void )av;
		perror(CLR_RED"Error:\nIncorrect # arguments:"
			CLR_YLLW"./bin/cub3d '[.cub]'"RST_ALL);
		return (1);
	}
	else
	{
		map_path = av[1];
		if (!check_file_format_n_extention(map_path))
			return (1);
		else
		{
			check_data_map(map_path);
		}
	}
	return (0);
}
