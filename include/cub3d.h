/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:44:08 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/20 21:25:06 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <ctype.h>
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"
# include "structs.h"

# define RST			"\x1b[0m"
# define CLR_RED		"\x1b[31m"
# define CLR_GRN		"\x1b[32m"
# define CLR_YLLW		"\x1b[33m"
# define CLR_BLUE		"\x1b[34m"

# define WIN_W			1920
# define WIN_H			1080
# define TILE_SIZE		24

# define LEFT			65361
# define RIGHT			65363
# define TOUCH_A		97
# define TOUCH_S		115
# define TOUCH_D		100
# define TOUCH_W		119

# define NO_ID			"NO"
# define SO_ID			"SO"
# define WE_ID			"WE"
# define EA_ID			"EA"
# define F_ID			"F"
# define C_ID			"C"

# define EXTENSION_LEN   4


int		check_file_format_n_extention(char *file);
int		check_data_map(char *file_name, t_cub *data);


// simple tools
int		ft_isspace(int s);
void	*s_malloc(size_t bytes);
void	free_struct(t_cub *data);
void	print_array(char **arr);


// init
t_cub	*init_variables(t_cub *data);
void	process_params(char *line, t_cub *data, char *id);
void	colors_rgb(char *line, char *id, t_cub *data);
int		check_for_params(char *map_path, t_cub *data);
void	colors_f_c(char *line, t_cub *data, char *id);
int		valid_rgb(char *s);
void	clean_line(char *s);
void	read_map(t_cub *data, char *line, int fd);
int		locate_player(t_cub *data);
int		fill_validation(char **map, int y, int x);
void	validate_map(t_cub *data);
int		empty_line(char *s);


// error handling and frees
void	s_free(void *ptr);
void	s_array_free(char **s);
void	error_map_param(char *line, int fd, t_ecode code);
void	error_texture_path(char *line, t_ecode code, char *id, t_cub *data);

// loop principal
int		game_loop(t_game *game);
int     close_windows(t_game *game);
int     key_press(int keycode, t_game *game);
void	init_player(t_game *game);

// dibujo
void	draw_pixel(t_mlx *mlx, int x, int y, int color);
int		draw_map(t_game *game);
void	clear_window(t_mlx *mlx, int color);
int		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//	utils
void	destroy(t_game *game);


/*A MODO SUGERENCIA ...

// 1. dLeer y almacenar el grid del mapa
char	**parse_map_grid(int fd, t_cub *data);

// 2. Validar caracteres del mapa (solo 0,1,N,S,E,W,espacio)
int		validate_map_chars(char **grid);

// 3. Encontrar posición inicial del jugador
int		find_player_position(t_map *map);

// 4. Verificar que el mapa esté cerrado por paredes
int		is_map_closed(char **grid);
*/
#endif
