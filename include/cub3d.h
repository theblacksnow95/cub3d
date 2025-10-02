/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:44:08 by emurillo          #+#    #+#             */
/*   Updated: 2025/10/02 14:26:43 by emurillo         ###   ########.fr       */
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

# define RST_ALL          "\x1b[0m"
# define CLR_RED          "\x1b[31m"
# define CLR_GRN        "\x1b[32m"
# define CLR_YLLW       "\x1b[33m"
# define CLR_BLUE         "\x1b[34m"

int		check_file_format_n_extention(char *file);
int		check_data_map(char *file_name);



#endif


