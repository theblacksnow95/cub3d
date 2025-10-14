/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/14 19:35:21 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub		*data;

	data = s_malloc(sizeof(t_cub));
	data = init_variables(data);
	if (ac != 2)
	{
		perror(CLR_RED"Error:\nIncorrect # arguments:"
			CLR_YLLW"./bin/cub3d '[.cub]'"RST_ALL);
		return (1);
	}
	else
	{
		data->map_path = av[1];
		// if (!check_file_format_n_extention(data->map_path))
		// 	return (1);
		// else
		// {
		// 	check_data_map(data->map_path, data);
		// }
	}
	free(data);
	return (0);
}
