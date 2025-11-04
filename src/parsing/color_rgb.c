/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:09:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/04 17:33:05 by emurillo         ###   ########.fr       */
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

void	*valid_nums(char **tmp, t_rgb *data, char *line)
{
	int	i;
	int	num;

	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	tmp = 0;
	while (*tmp)
	{
		num = ft_atoi(*tmp);
		if (num > -1 && num < 256)
		{
			if (i == 0)
				data->r = num;
			if (i == 1)
				data->g = num;
			if (i == 2)
				data->b = num;
		}
		else
			error_texture_path(line, E_color, C_ID, data);
		printf("color value: %d\n", num);
		tmp++;
	}
}

int	*colors_rgb(char *line, t_cub *data)
{
	char	**tmp;
	char	*p;
	int		*rgb;

	p = ft_strdup(line);
	if (!valid_rgb(p))
	{
		printf("return code [%d]\n", valid_rgb(p));
		return (NULL);
	}
	while (*p)
	{
		if (*p == '(' || *p == ')'
			|| *p == ' ' || *p == '\t')
			*p = ',';
		p++;
	}
	tmp = ft_split(line, ',');
	valid_nums(tmp, data, line);
	free(tmp);
	return (rgb);
}

