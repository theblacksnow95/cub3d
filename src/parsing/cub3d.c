/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:38:26 by emurillo          #+#    #+#             */
/*   Updated: 2025/09/26 16:38:56 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

/// cc - -I include/libft -I include/ml_linux -I include src/parsing/cub3d.c -o
//                   test  -L include/ml_linux -L include/libft -lft -lmlx

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		(void )av;
		ft_printf("Error: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}
