/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:23:23 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/08 11:56:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * This function checks that the file is correct, verifying that it is not a
 * folder and that the format is valid. The extension must be [".cub"]
 *
 * On error it returns 0.
 * @param file The path to the file, must be equal to argv[1]
*/
int	check_file_format_n_extention(char *file)
{
	int	fd;

	if (!file)
		return (0);
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		ft_printf(CLR_RED "Error: %s\n%s\n" RST_ALL, file, strerror(errno));
		return (0);
	}
	file = file + (ft_strlen(file) - EXTENSION_LEN);
	if (ft_strncmp(file, ".cub", EXTENSION_LEN))
	{
		ft_printf(CLR_RED"Error:\nIncorrect format [.cub] [KO]..\n"RST_ALL);
		close(fd);
		return (0);
	}
	ft_printf(CLR_GRN"Extension is correct\n\n"RST_ALL);
	close(fd);
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
