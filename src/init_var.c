/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:44:04 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/14 19:34:37 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_variables(t_cub *data)
{
	data->no_texture = s_malloc(sizeof(t_texture));
	data->so_texture = s_malloc(sizeof(t_texture));
	data->we_texture = s_malloc(sizeof(t_texture));
	data->ea_texture = s_malloc(sizeof(t_texture));
	return (data);
}
