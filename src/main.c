/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:34 by anoviedo          #+#    #+#             */
/*   Updated: 2025/12/13 11:40:36 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int(int r, int g, int b)
{
	int	color;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0x000000);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

static int	init_game(t_cub *game)
{
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!game->mlx.win)
		return (perror("windows error"), 1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_W, WIN_H);
	if (!game->mlx.img)
		return (perror("image error"), 1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_len, &game->mlx.endian);
	if (!game->mlx.addr)
		return (perror("address error"), 1);
	return (0);
}

int	game_loop(t_cub *game)
{
	double	now;

	now = get_time_ms();
	game->tm.frame_time = now - game->tm.old_time;
	game->tm.old_time = now;
	clear_window_select(&game->mlx, game->c_rgb->ceiling, 1, game);
	clear_window_select(&game->mlx, game->f_rgb->floor, 0, game);
	cast_all_rays(game);
	movements(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	if (game->mini == true)
		draw_map(game);
	return (0);
}

void	render_game(t_cub *game)
{
	void	*win;

	win = game->mlx.win;
	mlx_hook(win, 17, 0, close_windows, game);
	mlx_hook(win, 2, 1L << 0, key_press, game);
	mlx_hook(win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx.mlx, game_loop, game);
	game->f_rgb->floor = rgb_to_int
		(game->f_rgb->r, game->f_rgb->g, game->f_rgb->b);
	game->c_rgb->ceiling = rgb_to_int
		(game->c_rgb->r, game->c_rgb->g, game->c_rgb->b);
}

int	main(int ac, char **av)
{
	t_cub		game;

	if ((WIN_H < 500 || WIN_H > 1440) || (WIN_W < 600 || WIN_W > 2560))
		return (printf("bad - resolution - limit (W - 2560 x H - 1440)\n"), 1);
	if ((TILE_SIZE < 10 || TILE_SIZE > 20))
		return (printf("bad - size tile (10 ~ 20)\n"), 1);
	if (!check_file_format_n_extention(av[1]) || ac != 2)
		return (ft_printf(CLR_RED"Error:\nIncorrect # arguments:"
				CLR_YLLW"./bin/cub3d '[*file*.cub]'\n"RST_ALL), 1);
	init_variables(&game);
	game.map_path = av[1];
	if (!check_for_params(game.map_path, &game))
		return (close_windows(&game), 1);
	init_player(&game);
	if (init_game(&game))
		close_windows(&game);
	render_game(&game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
