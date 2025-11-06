/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:54:51 by anoviedo          #+#    #+#             */
/*   Updated: 2025/11/06 14:18:21 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MLX
#define STRUCT_MLX

#include "cub3d.h"
#include "structs.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*player;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			win_width;
	int			win_height;
	int			tile_size;
	int			player_x;
	int			player_y;
	int			total_collectibles;
	int			collected;
	int			move;
	t_textures	img;
}				t_game;

#endif
