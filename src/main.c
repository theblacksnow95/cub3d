/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:34 by anoviedo          #+#    #+#             */
/*   Updated: 2025/11/09 01:14:21 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	mlx_init ... inicializa el puntero necesario para el resto de parametros
	de minilibx, si falla devuelve null.
	internamente conecta el programa con x server que es un servidor display.
	reserva algunas estructuras tambien.*/
static void	init_game(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		exit(1);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!game->mlx.win)
		exit (1);
}

/*mlx_hook 17 = X presionada*/
int	main(void)
{
	t_game game;

	init_game(&game);
	mlx_hook(game.mlx.win, 17, 0, close_windows, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}

/*
//	comparo el nombre del archivo para que tenga la extension correcta
static int	validation(char *av)
{
	if (ft_strlen(av) < 5)
		return (1);
	av = ft_strchr(av, '.');
	if (!av)
		return(1);
	if (!ft_strncmp(av, ".cub\0", 5))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
    t_game game;

	// 1. Validar argumentos
	if (ac != 2)
		return(perror("you need only one map argument *.cub"), 1);
	if (validation(av[1]))
		return(perror("incorrect extension - necessary=\"maps_name.cub\""), 1);
    // 2. Parsear archivo .cub = hecho por ggeeenrrry
    // 3. Inicializar MiniLibX
    // 4. Inicializar estructuras del juego
    // 5. Bucle principal
    // 6. Limpieza al salir
	return(0);
}
*/
