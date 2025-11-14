/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:37:17 by antuel            #+#    #+#             */
/*   Updated: 2025/11/14 23:48:47 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  funcion para cerrar la ventana con escape */
int close_windows(t_game *game)
{
    mlx_destroy_window(game->mlx.mlx, game->mlx.win);
    exit(0);
    return (0);
}

/*   65307 = tecla ESC en X11 --- es decir, cerramos la ventana*/
int key_press(int keycode, t_game *game)
{
    printf("Key pressed: %d\n", keycode);//debug pour savoir code de la touche
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx.mlx, game->mlx.win);
        exit(0);
    }
    return (0);
}