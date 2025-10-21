/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:09:32 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/21 11:20:06 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	expect(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static int	valid_rgb(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
	{
		if (*s == ')')
			if (!expect(tmp, '('))
				return (0);
		if (*s == '(')
			if (!expect(tmp, ')'))
				return (0);
		if (ft_isdigit(*s)
			|| *s == '(' || *s == ')'
			|| *s == ',' || *s == ' '
			|| *s == '\t')
			s++;
		else
			return (0);
	}
	return (1);
}

int	valid_nums(char **rgb)
{
	int	i;

	i = 0;

	while (rgb[i])
		i++;
	if (i != 3)
		return (0);

}

char	**colors_rgb(char *line, char *id)
{
	char	**tmp;
	char	*p;

	line = move_line_to_path(line, id);
	p = line;
	if (!valid_rgb(p))
		error_texture_path(p, id);
	while (*p)
	{
		if (*p == '(' || *p == ')'
			|| *p == ' ' || *p == '\t')
			*p = ',';
		p++;
	}
	tmp = ft_split(line, ',');
	return (tmp);
}

