/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/11 10:51:26 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

// Para guardar cada textura en un puntero void con un flag de si ya se ha
// cargado, va a cambiar
typedef struct s_texture
{
	void		*id_texture;
	int			*rendered;
	int			full;
}				t_texture;

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
	E_texture,
	E_color,
	E_PARAM,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_F,
	E_C,
}	t_ecode;

// Estructura principal que usa punteros con punteros a otras estructuras
typedef struct s_cub
{
	int			params_cnt;
	char		*map_path;
	void		*ptr_mlx;
	void		*win_ptr;
	t_texture	*no_texture;
	t_texture	*so_texture;
	t_texture	*we_texture;
	t_texture	*ea_texture;
	t_rgb		*f_rgb;
	t_rgb		*c_rgb;
	int			img_h;
	int			img_w;
	int			i;
}	t_cub;

/* a modo sugerencia para el parsing del mapa...
// for map_parser.c
typedef struct s_map {
    char	**grid;
    int		width;
    int		height;
    int		player_x;
    int		player_y;
    char	player_dir;
} 			t_map;*/

/*datos del jugador, posicion, direccion donde mira...*/
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

/*	struct para los parametros de minilibx
	contexto, ventana, imagen, puntero a bytes
	addr → 			puntero a la dirección de memoria del buffer de la imagen.
	bpp → 			bits por pixel.
	line_len → 		cuántos bytes ocupa una fila de la imagen.
	*/
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_mlx;

/*	agrupa todo lo relacionado con MiniLibX,*/
typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	char		**map;
	int			map_width;
	int			map_height;
}				t_game;

#endif

