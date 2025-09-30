/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
/*   Updated: 2025/09/30 17:03:51 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

int	check_file_format_n_extention(char *file)
{
	int	fd;

	if (!file)
		return (0);
	fd = open(file, O_RDWR);
	if (fd <= 1)
	{
		ft_printf(CLR_RED "Error: \n%s\n" RST_ALL, strerror(errno));
		return (0);
	}
	if (fd)
	{
		file = file + (ft_strlen(file) - 4);
		if (ft_strncmp(file, ".cub", 4))
		{
			ft_printf(CLR_RED"Error:\nIncorrect format [.cub] [KO]..\n"RST_ALL);
			exit(1);
		}
		ft_printf(CLR_GRN"Extention is correct\n"RST_ALL);
		return (1);
	}
	return (1);
}

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
		check_file_format_n_extention(map_path);
	}
	return (0);
}
