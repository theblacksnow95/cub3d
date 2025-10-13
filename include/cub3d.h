/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:44:08 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/13 15:44:20 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <mlx.h>
# include <errno.h>
# include "libft.h"
# include <ctype.h>
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

# define EXTENSION_LEN   4


int		check_file_format_n_extention(char *file);
int		check_data_map(char *file_name, t_cub data);


// error handling and frees

void	s_free(void *ptr);
int		error_map_param(char *line, int fd, t_ecode code);
int		error_texture_path(char *line, t_ecode code);
int		process_params(char *line, t_cub *data, char *id);

#endif
