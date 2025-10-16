/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:19:46 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/16 18:10:47 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	id_validation(t_cub *data, char *line)
{
	int	len_id;

	if (!line)
		return (1);
	while (ft_isspace(*line) && line++)
	{
	}
	len_id = first_word(line);
	if (!ft_strncmp(line, NO_ID, ft_strlen(len_id)) && !data->no_texture->full)
		process_params(line, data, NO_ID);
	if (!ft_strncmp(line, SO_ID, ft_strlen(len_id)) && !data->so_texture->full)
		process_params(line, data, SO_ID);
	if (!ft_strncmp(line, WE_ID, ft_strlen(len_id)) && !data->we_texture->full)
		process_params(line, data, SO_ID);
	if (!ft_strncmp(line, EA_ID, ft_strlen(len_id)) && !data->ea_texture->full)
		process_params(line, data, SO_ID);
	if (!ft_strncmp(line, F_ID, ft_strlen(len_id)) && !data->f_colors)
		colors_f_c(line, data, F_ID);
	if (!ft_strncmp(line, C_ID, ft_strlen(len_id)) && !data->c_colors)
		colors_f_c(line, data, C_ID);
}

int	check_for_params(char *map_path, t_cub *data)
{
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	// check de lineas duplicadas a anadir
	while (data->params_cnt < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		id_validation(data, line);
		if (line)
			s_free(line);
		if (data->params_cnt == 6)
		{
			break ;
		}
	}
	return (0);
}
