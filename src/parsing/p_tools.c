/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:49:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/16 18:19:54 by emurillo         ###   ########.fr       */
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

void	*s_malloc(size_t bytes)
{
	void	*var;

	var = malloc(bytes);
	if (!var)
	{
		perror("Error:\n Malloc errorm\n");
		return (NULL);
	}
	return (var);
}

static void	clear_textures(t_cub *data)
{
	s_free(data->no_texture);
	s_free(data->so_texture);
	s_free(data->we_texture);
	s_free(data->ea_texture);
}

void	free_struct(t_cub *data)
{
	if (!data)
		return ;
	clear_textures(data);
	mlx_destroy_display(data->ptr_mlx);
	if (data->ptr_mlx)
	{
		s_free(data->ptr_mlx);
	}
	s_free(data);
	exit(1);
}
