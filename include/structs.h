#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_texture
{
    void    *ID_texture;
    int     *rendered;
}   t_texture;

typedef struct s_cub
{
	int		params_cnt;
	char	*map_path;
    void    *ptr_mlx;
    t_texture    *NO_texture;
    t_texture    *SO_texture;
    t_texture    *WE_texture;
    t_texture    *EA_texture;
}   t_cub;

#endif

