/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:49:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/09 16:29:43 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	s_array_free(char **s)
{
	int	i;

	i = 0;
	if (!s || *s == NULL)
		return ;
	while (s[i])
	{
		s_free(s[i]);
		s[i] = NULL;
		i++;
	}
	s_free(s);
	s = NULL;
}

void	s_free(void *ptr)
{
	if (!ptr && *(&ptr) != NULL)
		return ;
	free(ptr);
	ptr = NULL;
}

void	*s_malloc(size_t bytes)
{
	void	*var;

	var = malloc(bytes);
	if (!var)
	{
		perror("Error:\n Malloc error\n");
		return (NULL);
	}
	return (var);
}

int	empty_line(char *s)
{
	while (*s != '\n')
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

void	print_array(char **arr)
{
	if (!arr || arr[0][0] == '\0')
		return ;
	while (*arr)
	{
		ft_printf(CLR_BLUE"%s\n"RST_ALL, *arr);
		arr++;
	}
	printf("\n");
}
