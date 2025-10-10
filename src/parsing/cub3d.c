/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/08 17:19:40 by emurillo         ###   ########.fr       */
=======
/*   Updated: 2025/10/07 16:15:20 by emurillo         ###   ########.fr       */
>>>>>>> 9b9ce7f (ada)
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	data;

	if (ac != 2)
	{
		perror(CLR_RED"Error:\nIncorrect # arguments:"
			CLR_YLLW"./bin/cub3d '[.cub]'"RST_ALL);
		return (1);
	}
	else
	{
		data.map_path = av[1];
		if (!check_file_format_n_extention(data.map_path))
			return (1);
		else
		{
			check_data_map(data.map_path, data);
		}
	}
	return (0);
}
