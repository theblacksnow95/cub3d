/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map _check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:49:05 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/14 16:22:55 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_validation(t_cub *data)
{
	if (!locate_player(data))
		error_map_param(data->line, data->fd, E_MAP);
}
