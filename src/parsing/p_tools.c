/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:49:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/23 18:24:38 by antuel           ###   ########.fr       */
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
