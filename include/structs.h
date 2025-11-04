/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:24 by emurillo          #+#    #+#             */
/*   Updated: 2025/11/04 17:27:48 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_texture
{
	void	*id_texture;
	int		*rendered;
	int		full;
}	t_texture;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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
	int			*f_colors;
	int			*c_colors;
	int			img_h;
	int			img_w;
}	t_cub;

#endif

