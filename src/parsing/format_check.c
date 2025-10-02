/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:23:23 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/02 17:17:22 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * This function checks that the file is correct, verifying that it is not a
 * folder and that the format is valid. The extension must be [".cub"]
 *
 * On error it returns 1.
 * @param file The path to the file, must be equal to argv[1]
*/
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

int	check_data_map(char *file_name)
{
	char	*line;
	int		params_cnt;
	int		fd;

	fd = open(file_name, O_RDWR);
	while (params_cnt < 6 && (*file_name != '1' || *file_name != '0'))
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		
	}
}
