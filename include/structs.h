/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/17 15:44:03 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_flood
{
	bool	done;
	bool	error;
}	t_flood;


// Para guardar cada textura en un puntero void con un flag de si ya se ha
// cargado, va a cambiar

typedef struct s_texture
{
	void	*id_texture;
	int		*rendered;
	int		full;
}	t_texture;

// Para guardar los colores rgb y un flag cuando se hayan acabado de cargar

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	full;
}	t_rgb;

// Codidos de errores que uso para las texturas, va a cambiar

typedef enum e_code
{
	E_TEXTURE,
	E_COLOR,
	E_PARAM,
	E_MAP
}	t_ecode;

// Estructura principal que usa punteros con punteros a otras estructuras

typedef struct s_cub
{
	int			params_cnt;
	char		*map_path;
	char		**map;
	void		*ptr_mlx;
	void		*win_ptr;
	t_texture	*no_texture;
	t_texture	*so_texture;
	t_texture	*we_texture;
	t_texture	*ea_texture;
	t_rgb		*f_rgb;
	t_rgb		*c_rgb;
	int			params_full;
	int			img_h;
	int			img_w;
	int			i;
	int			fd;
	char		*line;
	int			dups;
	int			x_p;
	int			y_p;
	int			ply;
}	t_cub;

#endif

