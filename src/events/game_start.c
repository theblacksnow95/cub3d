/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:37:17 by antuel            #+#    #+#             */
/*   Updated: 2025/11/09 01:12:20 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*funcion para cerrar la ventana desde la X*/
int close_windows(t_game *game)
{
    mlx_destroy_window(game->mlx.mlx, game->mlx.win);
    return (exit(0), 0);
}