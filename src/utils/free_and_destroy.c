/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 00:05:59 by antuel            #+#    #+#             */
/*   Updated: 2025/12/05 14:42:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	clear_textures(t_cub *data)
{
	if (data->no_texture && data->no_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->no_texture->id_texture);
	if (data->so_texture && data->so_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->so_texture->id_texture);
	if (data->we_texture && data->we_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->we_texture->id_texture);
	if (data->ea_texture && data->ea_texture->full)
		mlx_destroy_image(data->mlx.mlx, data->ea_texture->id_texture);
	s_free(data->no_texture);
	s_free(data->so_texture);
	s_free(data->we_texture);
	s_free(data->ea_texture);
	s_free(data->f_rgb);
	s_free(data->c_rgb);
}

int	close_windows(t_cub *game)
{
	if (!game)
		return (1);
	clear_textures(game);
	if (game->mlx.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
		game->mlx.mlx = NULL;
	}
	if (game->map)
		s_array_free(game->map);
	if (game->fd != -1)
		close(game->fd);
	exit(0);
}
