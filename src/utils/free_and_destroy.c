/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 00:05:59 by antuel            #+#    #+#             */
/*   Updated: 2025/11/17 23:04:48 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy(t_game *game)
{
	if (game->mlx.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
	}
}

/*  funcion para cerrar la ventana con escape */
int	close_windows(t_game *game)
{
	destroy(game);
    exit(0);
    return (0);
}
