/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:42:42 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/12 11:57:27 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_line(char *s)
{
	while (*s)
	{
		if (*s == ' ' || *s == '\t')
			*s = ',';
		s++;
	}
}

int	valid_rgb(char *s)
{
	char		*tmp;
	int			i;

	tmp = s;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			tmp[i] = '\0';
		i++;
	}
	while (*tmp)
	{
		if (ft_isdigit(*tmp)
			|| *tmp == ',' || *tmp == ' ' || *tmp == '\t')
			tmp++;
		else
		{
			return (0);
		}
	}
	return (1);
}

static int	is_to_big(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i > 3)
			return (1);
		i++;
	}
	return (0);
}

int	limit_digits(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_to_big(s[i]))
			return (0);
		i++;
	}
	return (1);
}
