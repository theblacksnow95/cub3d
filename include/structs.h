/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/12/05 14:22:07 by emurillo         ###   ########.fr       */
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

/*datos del jugador, posicion, direccion donde mira...*/
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	mov_speed;
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
	int		text_w;
	int		text_h;
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


// typedef struct s_ray
// {
// 	int		map_x;
// 	int		map_y;
// 	double	camera_x;

// 	double	plane_x;
// 	double	plane_y;
// 	double	rayDir_x;
// 	double	rayDir_y;
// 	double	side;
// 	double  perpwalldist;
// }	t_ray;

// Codidos de errores que uso para las texturas, va a cambiar
typedef enum e_code
{
	E_TEXTURE,
	E_COLOR,
	E_PARAM,
	E_MAP,
	E_NOPLYR,
	E_CHARS,
	E_CLOSEDM,
	E_NO_ID
}	t_ecode;

typedef struct s_ray
{
	double	cameraX;
	double	raydirX;
	double	raydirY;
	double	deltaX;
	double	deltaY;
	double	sideX;
	double	sideY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		side;
	double	perpwalldist;
	double	dir_x;
	double	dir_y;
}			t_ray;

// Estructura principal que usa punteros con punteros a otras estructuras
typedef struct s_cub
{
	int			params_cnt;
	char		*map_path;
	char		**map;
	t_ray		ray;
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
	int			x_p; // mover a player
	int			y_p; // mover a player
	int			ply;
	bool		mini;
	t_mlx		mlx;
	t_player	player;
}				t_cub;

#endif
