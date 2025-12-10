/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:19:46 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/10 11:43:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(t_cub *data)
{
	while (data->line)
	{
		s_free(data->line);
		data->line = get_next_line(data->fd);
	}
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

int	not_id_present(char *line, int len, t_cub *data)
{
	if ((!ft_strncmp(line, NO_ID, len) && !ft_strncmp(NO_ID, line, 2))
		|| (!ft_strncmp(line, SO_ID, len) && !ft_strncmp(SO_ID, line, 2))
		|| (!ft_strncmp(line, WE_ID, len) && !ft_strncmp(WE_ID, line, 2))
		|| (!ft_strncmp(line, EA_ID, len) && !ft_strncmp(EA_ID, line, 2))
		|| !ft_strncmp(line, F_ID, len)
		|| !ft_strncmp(line, C_ID, len)
		|| empty_line(line))
		return (0);
	else
	{
		data->dups = 1;
		error_handler(data->line, E_NO_ID, EMPTY_ID, data);
		return (1);
	}
}

int	id_validation(t_cub *data, char *line)
{
	int	len_id;

	if (!line)
		return (0);
	if (empty_line(line))
		return (0);
	while (ft_isspace(*line) && line++)
	{
	}
	len_id = first_word(line);
	if (!ft_strncmp(line, NO_ID, len_id) && !ft_strncmp(NO_ID, line, 2))
		process_params(line, data, NO_ID);
	if (!ft_strncmp(line, SO_ID, len_id) && !ft_strncmp(SO_ID, line, 2))
		process_params(line, data, SO_ID);
	if (!ft_strncmp(line, WE_ID, len_id) && !ft_strncmp(WE_ID, line, 2))
		process_params(line, data, WE_ID);
	if (!ft_strncmp(line, EA_ID, len_id) && !ft_strncmp(EA_ID, line, 2))
		process_params(line, data, EA_ID);
	if (!ft_strncmp(line, F_ID, len_id))
		colors_f_c(line, data, F_ID);
	if (!ft_strncmp(line, C_ID, len_id))
		colors_f_c(line, data, C_ID);
	else if (not_id_present(line, len_id, data))
		return (0);
	return (1);
}

int	check_for_params(char *map_path, t_cub *data)
{
	data->fd = open(map_path, O_RDONLY);
	while (data->params_cnt < 6)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			return (0);
		if (id_validation(data, data->line))
			data->params_cnt++;
		if (data->dups)
		{
			while (data->line)
			{
				s_free(data->line);
				data->line = get_next_line(data->fd);
			}
			return (0);
		}
		if (data->line)
			s_free(data->line);
		if (data->params_cnt == 6)
			break ;
	}
	read_map(data, data->line, data->fd);
	return (1);
}
