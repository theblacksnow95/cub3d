/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:09:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/05 17:11:24 by emurillo         ###   ########.fr       */
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

static int	valid_rgb(char *s)
{
	char		*tmp;

	tmp = s;
	while (*tmp++)
	{
		if (*tmp == '\n')
			*tmp = '\0';
	}
	while (*tmp)
	{
		if (ft_isdigit(*tmp)
			|| *tmp == ',' || *tmp == 32
			|| *tmp == '\t')
		{
			tmp++;
		}
		// if (*tmp == ')')
		// 	if (!expect(tmp, '('))
		// 		return (0);
		// if (*tmp == '(')
		// {
		// 	if (!expect(tmp, ')'))
		// 		return (0);
		// }
		else
		{
			// printf("here [%c]", *tmp);
			return (0);
		}
	}
	return (1);
}

void	fill_c_rgb(t_cub *data, char *line, char *id, int num)
{
	if ((num > -1 && num < 256) && ft_strncmp(id, F_ID, 1))
	{
		if (data->i == 0)
			data->c_rgb->r = num;
		if (data->i == 1)
			data->c_rgb->g = num;
		if (data->i == 2)
			data->c_rgb->b = num;
		if (data->i == 3)
		{
			data->c_rgb->full = 1;
			return ;
		}
		data->i++;
	}
	else
		error_texture_path(line, E_color, id, data);
}

void	fill_f_rgb(t_cub *data, char *line, char *id, int num)
{
	if ((num > -1 && num < 256) && !ft_strncmp(id, C_ID, 1))
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
		data->i++;
	}
	else
		error_texture_path(line, E_color, id, data);
}

void	valid_nums(char **tmp, t_cub *data, char *id, char *line)
{
	int	i;
	int	num;


	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		error_texture_path(line, E_color, id, data);
	data->i = 0;
	tmp = 0;
	while (*tmp)
	{
		num = ft_atoi(*tmp);
		if (!ft_strncmp(id, F_ID, 1))
			fill_f_rgb(data, line, id, num);
		if (!ft_strncmp(id, C_ID, 1))
			fill_c_rgb(data, line, id, num);
		printf("color value: %d\n", num);
		tmp++;
	}
}

void	colors_rgb(char *line, char *id, t_cub *data)
{
	char	**tmp;
	char	*p;

	p = ft_strdup(line);
	printf("here!!\n");
	if (!valid_rgb(p))
	{
		printf("return code [%d]\n", valid_rgb(p));
		error_texture_path(line, E_color, id, data);
	}
	while (*p)
	{
		if (*p == '(' || *p == ')'
			|| *p == ' ' || *p == '\t')
			*p = ',';
		p++;
	}
	tmp = ft_split(line, ',');
	valid_nums(tmp, data, id, line);
	free(tmp);
}

