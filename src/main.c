/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:34 by anoviedo          #+#    #+#             */
/*   Updated: 2025/11/06 13:44:05 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*comparo el nombre del archivo para que tenga la extension correcta*/
static int	validation(char *av)
{
	if (ft_strlen(av) < 5)
		return (1);
	av = ft_strchr(av, '.');
	if (!av)
		return(1);
	if (!ft_strncmp(av, ".cub", 4))
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
    // 2. Parsear archivo .cub
    // 3. Inicializar MiniLibX
    // 4. Inicializar estructuras del juego
    // 5. Bucle principal
    // 6. Limpieza al salir
}
