/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:44:08 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/19 18:09:57 by emurillo         ###   ########.fr       */
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

# define NO_ID          "NO"
# define SO_ID          "SO"
# define WE_ID          "WE"
# define EA_ID          "EA"
# define F_ID           "F"
# define C_ID           "C"
# define EMPTY_ID          ""

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
void	error_handler(char *line, t_ecode code, char *id, t_cub *data);
void	error_map(t_cub *data);
void	free_exit(t_cub *data);

#endif
