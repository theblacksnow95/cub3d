/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:49:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/14 19:37:22 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	s_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

void	*s_malloc(size_t _size)
{
	void	*var;

	var = malloc(_size);
	if (!var)
	{
		perror("Error:\n Malloc errorm\n");
		return (NULL);
	}
	return (var);
}

void	free_struct(t_cub *data)
{
	if (!data)
		return ;
	else
	{
		s_free(data->no_texture);
		s_free(data->so_texture);
		s_free(data->we_texture);
		s_free(data->ea_texture);
	}
}
