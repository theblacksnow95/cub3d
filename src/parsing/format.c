/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:19:46 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/12 12:19:45 by emurillo         ###   ########.fr       */
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
		return (0);
	while (ft_isspace(*line) && line++)
	{
	}
	len_id = first_word(line);
	if (!ft_strncmp(line, NO_ID, len_id))
		process_params(line, data, NO_ID);
	if (!ft_strncmp(line, SO_ID, len_id))
		process_params(line, data, SO_ID);
	if (!ft_strncmp(line, WE_ID, len_id))
		process_params(line, data, WE_ID);
	if (!ft_strncmp(line, EA_ID, len_id))
		process_params(line, data, EA_ID);
	if (!ft_strncmp(line, F_ID, len_id))
		colors_f_c(line, data, F_ID);
	if (!ft_strncmp(line, C_ID, len_id))
		colors_f_c(line, data, C_ID);
	return (1);
}

int	check_for_params(char *map_path, t_cub *data)
{
	char	*line;

	data->fd = open(map_path, O_RDONLY);
	if (data->fd < 0)
		return (0);
	while (data->params_cnt < 6)
	{
		line = get_next_line(data->fd);
		if (!line)
			return (0);
		if (id_validation(data, line))
			data->params_cnt++;
		if (line)
			s_free(line);
		printf("count: %d\n", data->params_cnt);
		if (data->params_cnt == 6)
			break ;
	}
	data->map = read_map(data, line, data->fd);
	s_array_free(data->map);
	return (1);
}
