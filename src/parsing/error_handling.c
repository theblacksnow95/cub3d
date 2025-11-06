/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/05 17:05:09 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	error_map_param(char *line, int fd, t_ecode code)
{
	if (code == E_PARAM)
	{
		ft_printf(CLR_RED"Incorrect id check: %s\n"RST_ALL, line);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
	}
}

void	error_texture_path(char *line, t_ecode code, char *id, t_cub *data)
{
	if (code == E_texture)
		ft_printf("Error:\nTexture <%s> does not exist\n"\
CLR_RED"%s"CLR_RED, id, line);
	if (code == E_color)
		ft_printf("Error:\nIncorrect <%s> coordinates\n"\
CLR_RED"%s"CLR_RED, id, line);
	if (code == E_NO)
		ft_printf("Error:\nTexture <NO> does not exist\n"\
CLR_RED"%s"CLR_RED, line);
	if (code == E_SO)
		ft_printf("Error:\nTexture <SO> does not exist\n"\
CLR_RED"%s"CLR_RED, line);
	if (code == E_WE)
		ft_printf("Error:\nTexture <WE> does not exist\n"\
CLR_RED"%s"CLR_RED, line);
	if (code == E_EA)
		ft_printf("Error:\nTexture <EA> does not exist\n"\
CLR_RED"%s"CLR_RED, line);
	if (code == E_F)
		ft_printf("Error:\nIncorrect <F> coordinates\n"\
CLR_RED"%s"CLR_RED, line);
	if (code == E_C)
		ft_printf("Error:\nIncorrect <C> coordinates\n"\
CLR_RED"%s"CLR_RED, line);
	free_struct(data);
}
