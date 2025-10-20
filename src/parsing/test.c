/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:30:57 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/17 11:29:31 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**colors_rgb(char *line)
{
	char	**tmp;
	char		*p;

	// line = move_line_to_path(line, id);
	p = line;
	while (*p)
	{
		if (*p == '(' || *p == ')')
			*p = ',';
		p++;
	}
	tmp = ft_split(line, ',');
	return (tmp);
}

int	valid_rgb(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) || *s == '(' || *s == ')' || \
		*s == ',' || *s == ' ' || *s == '	')
			s++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char **words;
	char *str;

	str = av[1];
	if (!valid_rgb(str))
		return (ft_printf("Invalid line: %s\n", str), 1);
	words = colors_rgb(str);
	if (!words)
		return (1);
	if (ac == 2)
	{
		while (*words)
		{
			ft_printf("ret: %s\n", *words);
			words++;
		}
	}
	else 
		return (1);
	return (0);
}
