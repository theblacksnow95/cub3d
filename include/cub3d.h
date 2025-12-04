/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:44:08 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/02 20:52:23 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <mlx.h>
# include <errno.h>
# include <ctype.h>
# include <stdbool.h>
# include "libft.h"
# include "structs.h"

# define RST_ALL          "\x1b[0m"
# define CLR_RED          "\x1b[31m"
# define CLR_GRN          "\x1b[32m"
# define CLR_YLLW         "\x1b[33m"
# define CLR_BLUE         "\x1b[34m"

# define WIN_W			1080
# define WIN_H			940
# define TILE_SIZE		16

# define NO_ID          "NO"
# define SO_ID          "SO"
# define WE_ID          "WE"
# define EA_ID          "EA"
# define F_ID           "F"
# define C_ID           "C"
# define EMPTY_ID          ""

# define EXTENSION_LEN	4
# define COLLITION_RAD	0.25
# define PLAYER_RAD		3


int		check_file_format_n_extention(char *file);
int		check_data_map(char *file_name, t_cub *data);


// simple tools
int		ft_isspace(int s);
void	*s_malloc(size_t bytes);
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
void	error_handler(char *line, t_ecode code, char *id, t_cub *data);
void	error_map(t_cub *data);

// loop principal
int		game_loop(t_cub *game);
int		key_press(int keycode, t_cub *game);
void	init_player(t_cub *game);

// dibujo
void	draw_pixel(t_mlx *mlx, int x, int y, int color);
int		draw_map(t_cub *game);
void	clear_window(t_mlx *mlx, int color);
int		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		draw_player(t_mlx *mlx, double x, double y, int color);
int		cast_all_rays(t_cub *game);


//	utils
int		close_windows(t_cub *game);

#endif
