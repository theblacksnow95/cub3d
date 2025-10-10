/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:23:23 by emurillo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/08 17:20:12 by emurillo         ###   ########.fr       */
=======
/*   Updated: 2025/10/07 16:14:56 by emurillo         ###   ########.fr       */
>>>>>>> 9b9ce7f (ada)
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

int	ft_count_words(char *line)
{
	int	cnt_wrd;
	int	inword;

	inword = 0;
	cnt_wrd = 0;
	while (*line)
	{
		if (!ft_isspace(*line))
		{
			inword = 1;
			cnt_wrd++;
			while (!ft_isspace(*line))
				line++;
		}
		else
		{
			if (inword)
				inword = 0;
		}
		line++;
	}
	return (cnt_wrd);
}

static int	first_word(char *line)
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

	while (ft_isspace(*line) && line++)
	{
	}
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
	else if (!ft_strncmp(line, C_ID, len))
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

int	check_data_map(char *file_name, t_cub data)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
<<<<<<< HEAD
	params_cnt = 0;
	while (params_cnt < 6)
=======
	data.params_cnt = 0;
	while (data.params_cnt < 6)
>>>>>>> 9b9ce7f (ada)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
<<<<<<< HEAD
		check_id(line);
		params_cnt++;
		ft_printf("Params found--> %d\n", params_cnt);
		if (params_cnt == 6)
=======
		if (!check_id(line))
			return (1);
		data.params_cnt++;
		if (data.params_cnt == 6)
>>>>>>> 9b9ce7f (ada)
		{
			ft_printf("All data collected.\n");
			s_free(line);
			break ;
		}
		s_free(line);
	}
	close(fd);
	// ft_printf("line %s", line);
	return (0);
}

