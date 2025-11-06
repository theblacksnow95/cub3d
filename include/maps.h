/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:39:41 by antuel            #+#    #+#             */
/*   Updated: 2025/11/06 10:13:53 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
#define MAPS_H

#include "cub3d.h"
#include "structs.h"



// 1. dLeer y almacenar el grid del mapa
char	**parse_map_grid(int fd, t_cub *data);

// 2. Validar caracteres del mapa (solo 0,1,N,S,E,W,espacio)
int		validate_map_chars(char **grid);

// 3. Encontrar posición inicial del jugador
int		find_player_position(t_map *map);

// 4. Verificar que el mapa esté cerrado por paredes
int		is_map_closed(char **grid);

#endif
