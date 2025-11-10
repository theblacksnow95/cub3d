#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include "libft.h"

// cc open.c -o open -g -I ../libraries/ml_linux/ -I ../libraries/libft/ -L ../libraries/ml_linux/ -L ../libraries/libft/ -lft -lmlx -lXext -lX11 -lz -lm


int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	else
	{
		char *s = av[1];
		int fd;
		fd = open(s, O_RDONLY);
		if (fd < 1)
		{
			printf("Error fd not a valid file: %s\n" "FD: [%d]\n", s, fd);
			return (1);
		}
		else
		{	
			void *mlx;
			void *image;
			int	h;
			int	w;
			char *line;
			int		i = 0;

			line = get_next_line(fd);
			while (*line == '\t' && line++)
			{
				while (*line == 'N' || *line == 'O')
				{
					line++;
					while (*line == '\t' || *line == ' ')
						line++;
				}
			}
			while (line[i])
			{
				if (line[i] == '\n')
					line[i] = '\0';
				i++;
			}
			int f2;
			f2 = open(line, O_RDONLY);
			if (!f2)
				printf("error filepath: %s\n", line);
			else
				printf("f2: %d\n", f2);
			printf("correct file: [%s]\n %d\n", line, fd);
			mlx = mlx_init();
			image = mlx_xpm_file_to_image(mlx, line, &w, &h);
			if (!image)
			{
				printf("error image: %s\n", line);
				printf("value pointer: %p\n", image);
			}
			else
				printf("*mlx: %p\n", mlx);
				printf("*image: %p\n", image);
		}
	}
	return (0);
}
