/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:05:14 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/05 18:09:09 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_vars	mlx;
	t_vars	lenght;

	map = ft_calloc(1, sizeof(t_map));
	if (ac != 2)
		return (0);
	lenght.lenght = 44;
	init_mlx(&mlx);
	mlx.mlx = mlx_init();
	init_map(av[1], map);
	mlx.win = mlx_new_window(mlx.mlx, co_x(map), co_y(map), "So_long");
	load_image(&mlx, lenght);
	check_map(&mlx, map);
	build_map(&mlx, map, lenght);
	events_hooks(&mlx);
	change_map(&mlx, map);
	mlx.map = map;
	mlx_loop(mlx.mlx);
	ft_close(&mlx);
	return (0);
}
