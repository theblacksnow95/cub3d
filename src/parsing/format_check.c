/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:23:23 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/02 20:04:11 by emurillo         ###   ########.fr       */
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


int	ft_isspace(int s)
{
	if (!s)
		return (1);
	if ((s >= 9 && s <= 13) || s == 32 )
	{
		ft_printf("%c\n", s);
		return (0);
	}
	else
	{
		ft_printf("Char: %c\n", s);
		return (1);
	}
}

int	check_id(char *line)
{
	int		len;
	// int		id_len;

	while (ft_isspace(*line))
		(*line)++;
	len = 0;
	while (!ft_isspace(*line))
	{
		(*line)++;
		len++;
	}
	if (!ft_strncmp(line, NO_ID, len))
	{
		ft_printf("Correct _id NO: %s\n", line);
		ft_printf("Len of ID: #%d\n", len);
		free(line);
		exit (1);
	}
	return (0);
}

int	check_data_map(char *file_name)
{
	char	*line;
	int		params_cnt;
	int		fd;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		return (1);
	params_cnt = 0;
	while (params_cnt < 6 && (*file_name != '1' || *file_name != '0'))
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (!check_id(line))
			return (1);
	}
	return (0);
}
