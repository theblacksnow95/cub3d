/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:34 by anoviedo          #+#    #+#             */
/*   Updated: 2025/11/21 15:26:22 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	mlx_init ... inicializa el puntero necesario para el resto de parametros
	de minilibx, si falla devuelve null.
	internamente conecta el programa con x server que es un servidor display.
	reserva algunas estructuras tambien.*/
static int	init_game(t_cub *game)
{
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!game->mlx.win)
		return (perror("windows error"), 1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_W, WIN_H);
	if (!game->mlx.img)
		return (perror("image error"), 1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
		&game->mlx.line_len, &game->mlx.endian);
	if (!game->mlx.addr)
		return (perror("address error"), 1);
	return (0);
}

/*	mlx_hook 17 = X presionada
	mlx_hook_key corresponde a la reaccion de la ventana con las teclas
	en este caso es para cerrar con escape(key_press)*/
int	main(int ac, char **av)
{
	t_cub		game;

	if (!check_file_format_n_extention(av[1]) || ac != 2)
	{
		perror(CLR_RED"Error:\nIncorrect # arguments:"
			CLR_YLLW"./bin/cub3d '[*file*.cub]'"RST_ALL);
		return (1);
	}
	ft_bzero(&game, sizeof(t_cub));
	init_variables(&game);
	game.map_path = av[1];
	if (!check_for_params(game.map_path, &game))
	{
		error_handler(NULL, E_MAP, EMPTY_ID, &game);
		free_struct(&game);
		return (1);
	}
	init_player(&game);
	if (init_game(&game))
		return (free_struct(&game), 1);
	draw_map(&game);
	mlx_put_image_to_window(game.mlx.mlx, game.mlx.win, game.mlx.img, 0, 0);
	mlx_hook(game.mlx.win, 17, 0, close_windows, &game);
	mlx_key_hook(game.mlx.win, key_press, &game);
	mlx_loop(game.mlx.mlx);
	free_struct(&game);
	return (0);
}
