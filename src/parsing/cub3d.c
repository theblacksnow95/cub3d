/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/19 18:45:05 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub		data;

	if (!check_file_format_n_extention(av[1]) || ac != 2)
	{
		perror(CLR_RED"Error:\nIncorrect # arguments:"
			CLR_YLLW"./bin/cub3d '[*file*.cub]'"RST_ALL);
		return (1);
		printf("%s", av[1]);
	}
	ft_bzero(&data, sizeof(t_cub));
	init_variables(&data);
	data.map_path = av[1];
	if (!check_for_params(data.map_path, &data))
	{
		error_handler(NULL, E_MAP, EMPTY_ID, &data);
		free_struct(&data);
		return (1);
	}
	free_struct(&data);
	return (0);
}
