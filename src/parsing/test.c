/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:30:57 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/03 13:58:32 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	expect(char *s, char c);
static int	valid_rgb(char *s);

// char	**colors_rgb(char *line)
// {
// 	char	**tmp;
// 	char	*p;

// 	// line = move_line_to_path(line, id);
// 	p = line;
// 	while (*p)
// 	{
// 		if (*p == '(' || *p == ')'
// 			|| *p == ' ' || *p == '\t')
// 			*p = ',';
// 		p++;
// 	}
// 	tmp = ft_split(line, ',');
// 	return (tmp);
// }

// static int	expect(char *s, char c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return (1);
// 		s++;
// 	}
// // 	return (0);
// // }

// static int	valid_rgb(char *s)
// {
// 	char	*tmp;

// 	tmp = s;
// 	while (*s)
// 	{
// 		if (*s == ')')
// 			if (!expect(tmp, '('))
// 				return (0);
// 		if (*s == '(')
// 			if (!expect(tmp, ')'))
// 				return (0);
// 		if (ft_isdigit(*s)
// 			|| *s == '(' || *s == ')'
// 			|| *s == ',' || *s == ' '
// 			|| *s == '\t')
// 			s++;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

int	main(int ac, char **av)
{
	char	**words;
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		if (!valid_rgb(str))
			return (ft_printf("Invalid line: %s\n", str), 1);
		words = colors_rgb(str);
		if (!words)
			return (1);
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
