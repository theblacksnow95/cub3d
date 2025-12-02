/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:33:32 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/01 16:42:00 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rays(t_cub *game, t_ray *ray, t_player *player)
{
	double	line_w;
	
	
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->dir_x = game->player.dir_x;
	ray->dir_x = game->player.dir_y;
	ray->plane_x = game->player.plane_x;
	ray->plane_y = game->player.plane_y;
	line_w = ft_strlen(game->map[ray->map_y]);
	ray->camera_x = 2 * (player->x / line_w - 1);
	ray->rayDir_x = ray->dir_x + (player->plane_x * ray->camera_x);
	ray->rayDir_y = ray->dir_y + (player->plane_y * ray->camera_x);
}
