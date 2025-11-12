/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:09:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/12 11:24:04 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	expect(char *s, char c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return (1);
// 		s++;
// 		if (*s == '\n')
// 			return (0);a
// 	}
// 	return (0);
// }

void	fill_c_rgb(t_cub *data, char *line, char *id, int num)
{
	// printf("idx: %d\n", data->i); //debug
	// printf("val num: %d\n", num); //debug
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
			// printf("rgb C full: %d\n", data->c_rgb->full); //debug

			return ;
		}
	}
	else
		error_texture_path(line, E_COLOR, id, data);
}

void	fill_f_rgb(t_cub *data, char *line, char *id, int num)
{
	// printf("idx: %d\n", data->i); //debug
	// printf("val num: %d\n", num); //debug
	if ((num > -1 && num < 256) && !ft_strncmp(id, F_ID, 1)
		&& !data->f_rgb->full)
	{
		if (data->i == 0)
			data->f_rgb->r = num;
		if (data->i == 1)
			data->f_rgb->g = num;
		if (data->i == 2)
			data->f_rgb->b = num;
		if (data->i == 2)
		{
			data->f_rgb->full = 1;
			// printf("rgb F full: %d\n", data->f_rgb->full); //debug
			return ;
		}
	}
	else
	{
		error_texture_path(line, E_COLOR, id, data);
	}
}

void	valid_nums(char **tmp, t_cub *data, char *id, char *line)
{
	int	i;
	int	num;


	i = 0;
	while (tmp[i])
		i++;
	// printf("value of i after: %d\n", i); // debug
	if (i != 3)
		error_texture_path(line, E_COLOR, id, data);
	data->i = 0;
	while (tmp[data->i])
	{
		num = ft_atoi(tmp[data->i]);
		if (!ft_strncmp(id, F_ID, 1))
			fill_f_rgb(data, line, id, num);
		if (!ft_strncmp(id, C_ID, 1))
			fill_c_rgb(data, line, id, num);
		data->i++;
		// printf("color value: %d\n", num); // debug
	}
	// printf("value f: %d,%d,%d\n", data->f_rgb->r, data->f_rgb->g, data->f_rgb->b); //debug
	// printf("value c: %d,%d,%d\n", data->c_rgb->r, data->c_rgb->g, data->c_rgb->b); //debug
}

void	colors_rgb(char *line, char *id, t_cub *data)
{
	char	**tmp;
	char	*p;

	p = ft_strdup(line);
	if (!valid_rgb(p))
	{
		// printf("return code [%d]\n", valid_rgb(p)); // debug
		error_texture_path(p, E_COLOR, id, data);
	}
	// printf("passed the valid_rgb: %s\n", p); // debug
	clean_line(p);
	tmp = ft_split(p, ',');
	// printf("%s,""%s""%s\n", *tmp, tmp[1], tmp[2]); //debug
	free(p);
	valid_nums(tmp, data, id, line);
	s_array_free(tmp);
}

