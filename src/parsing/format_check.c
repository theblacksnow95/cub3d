/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:23:23 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/04 18:50:02 by emurillo         ###   ########.fr       */
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
		file = file + (ft_strlen(file) - EXTENSION_LEN);
		if (ft_strncmp(file, ".cub", EXTENSION_LEN))
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
	if ((s >= 9 && s <= 13) || s == 32)
	{
		// ft_printf("%c\n", s);
		return (1);
	}
	return (0);
}

static int first_word(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (!ft_isspace(line[i]))
	{
		ret++;
		i++;
	}
	return (ret);
}

int	check_id(char *line)
{
	int		len;
	// int		id_len;
	// int		i;

	// i = 0;
	while (ft_isspace(*line) && line++)
	{
		// ft_printf("char == [%c]\n", *line);
	}
	len = 0;
	len = first_word(line);
	ft_printf("value of len %d\n", len);
	if (!ft_strncmp(line, NO_ID, len))
	{
		ft_printf(CLR_GRN"Correct ID NO name: %s"RST_ALL, line);
		return (1);
	}
	else if (!ft_strncmp(line, SO_ID, len))
	{
		ft_printf(CLR_GRN"Correct ID SO name: %s"RST_ALL, line);

		return (1);
	}
	else if (!ft_strncmp(line, WE_ID, len))
	{
		ft_printf(CLR_GRN"Correct ID WE name: %s"RST_ALL, line);

		return (1);
	}
	else if (!ft_strncmp(line, EA_ID, len))
	{
		ft_printf(CLR_GRN"Correct ID EA name: %s"RST_ALL, line);

		return (1);
	}
	else if (!ft_strncmp(line, F_ID, len))
	{
		ft_printf(CLR_GRN"Correct ID F name: %s\n"RST_ALL, line);

		return (1);
	}
	else if (!ft_strncmp(line, C_ID, len ))
	{
		ft_printf(CLR_GRN"Correct ID C name: %s\n"RST_ALL, line);
		return (1);
	}
	else
	{
		ft_printf(CLR_RED"Incorrect id NO: %s\n"RST_ALL, line);
		ft_printf(CLR_YLLW"Len of ID: #%d\n"RST_ALL, len);

		return (0);
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
		params_cnt++;
		ft_printf("Params found--> %d\n", params_cnt);
		if (params_cnt == 6)
		{
			ft_printf("All data collected.\n");
			break;
		}
	}
	// ft_printf("line %s", line);
	return (0);
}
