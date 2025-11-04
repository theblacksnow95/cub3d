/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/04 11:06:14 by emurillo         ###   ########.fr       */
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
		printf("%s", av[1]);
	}
	else
	{
		data->map_path = av[1];
		if (!check_file_format_n_extention(data->map_path))
			return (1);
		if (!check_for_params(data->map_path, data))
		{
			return (1);
		}
	}
	free_struct(data);
	return (0);
}
