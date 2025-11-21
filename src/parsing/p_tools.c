/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:49:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/21 15:22:58 by antuel           ###   ########.fr       */
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

static void	clear_textures(t_cub *data)
{
	if (data->no_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->no_texture->id_texture);
	if (data->so_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->so_texture->id_texture);
	if (data->we_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->we_texture->id_texture);
	if (data->ea_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->ea_texture->id_texture);
	s_free(data->no_texture);
	s_free(data->so_texture);
	s_free(data->we_texture);
	s_free(data->ea_texture);
	s_free(data->f_rgb);
	s_free(data->c_rgb);
	if (data->mlx.mlx)
		mlx_destroy_display(data->mlx.mlx);
}

void	free_struct(t_cub *data)
{
	if (data == NULL)
		return ;
	clear_textures(data);
	if (data->map)
		s_array_free(data->map);
	if (data->fd != -1)
		close(data->fd);
	data = NULL;
	if(data->mlx.mlx)
		free(data->mlx.mlx);
}
