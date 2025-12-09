/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:09:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/09 15:50:54 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_c_rgb(t_cub *data, char *line, char *id, int num)
{
	if ((num > -1 && num < 256) && !ft_strncmp(id, C_ID, 1)
		&& !data->c_rgb->full)
	{
		if (data->i == 0)
			data->c_rgb->r = num;
		if (data->i == 1)
			data->c_rgb->g = num;
		if (data->i == 2)
			data->c_rgb->b = num;
		if (data->i == 2)
		{
			data->c_rgb->full = 1;
			return ;
		}
	}
	else
	{
		error_handler(line, E_COLOR, id, data);
	}
}

void	fill_f_rgb(t_cub *data, char *line, char *id, int num)
{
	if ((num > -1 && num < 256) && !ft_strncmp(id, F_ID, 1)
		&& !data->f_rgb->full)
	{
		if (data->i == 0)
			data->f_rgb->r = num;
		if (data->i == 1)
			data->f_rgb->g = num;
		if (data->i == 2)
			data->f_rgb->b = num;
		if (data->i == 3)
		{
			data->f_rgb->full = 1;
			return ;
		}
	}
	else
		error_handler(line, E_COLOR, id, data);
}

void	valid_nums(char **tmp, t_cub *data, char *id, char *line)
{
	int	i;
	int	num;

	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
	{
		error_handler(line, E_COLOR, id, data);
	}
	data->i = 0;
	while (tmp[data->i] && !data->dups)
	{
		num = ft_atoi(tmp[data->i]);
		if (!ft_strncmp(id, F_ID, 1))
			fill_f_rgb(data, line, id, num);
		if (!ft_strncmp(id, C_ID, 1))
			fill_c_rgb(data, line, id, num);
		data->i++;
	}
}

void	colors_rgb(char *line, char *id, t_cub *data)
{
	char	**tmp;
	char	*p;

	p = ft_strdup(line);
	if (!valid_rgb(p))
	{
		error_handler(p, E_COLOR, id, data);
		s_free(p);
		return ;
	}
	clean_line(p);
	tmp = ft_split(p, ',');
	s_free(p);
	valid_nums(tmp, data, id, line);
	s_array_free(tmp);
}
