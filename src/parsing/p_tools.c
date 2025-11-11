/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:49:15 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/11 15:02:19 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	s_array_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

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
		perror("Error:\n Malloc error\n");
		return (NULL);
	}
	return (var);
}

static void	clear_textures(t_cub *data)
{
	mlx_destroy_image(data->ptr_mlx, data->no_texture->id_texture);
	mlx_destroy_image(data->ptr_mlx, data->so_texture->id_texture);
	mlx_destroy_image(data->ptr_mlx, data->we_texture->id_texture);
	mlx_destroy_image(data->ptr_mlx, data->ea_texture->id_texture);
	s_free(data->no_texture);
	s_free(data->so_texture);
	s_free(data->we_texture);
	s_free(data->ea_texture);
	s_free(data->f_rgb);
	s_free(data->c_rgb);
	mlx_destroy_display(data->ptr_mlx);

}

void	free_struct(t_cub *data)
{
	if (!data)
		return ;
	clear_textures(data);
	if (data->ptr_mlx)
		s_free(data->ptr_mlx);
	s_free(data);
}
