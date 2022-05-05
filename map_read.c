/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:42:46 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/05 17:54:17 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_vars mlx, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.wall, y, x);
	if (c == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.floor, y, x);
	if (c == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.piece, y, x);
	if (c == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.exit, y, x);
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.position, y, x);
		return (1);
	}
	return (0);
}

void	load_image(t_vars *mlx, t_vars lenght)
{
	mlx->img.wall = mlx_xpm_file_to_image(mlx->mlx, "./xpm/wall.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.wall)
		ft_putendl_fd("WALL : fail", 2);
	mlx->img.floor = mlx_xpm_file_to_image(mlx->mlx, "./xpm/floor.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.floor)
		ft_putendl_fd("FLOOR : fail", 2);
	mlx->img.piece = mlx_xpm_file_to_image(mlx->mlx, "./xpm/piece.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.piece)
		ft_putendl_fd("PIECE : fail", 2);
	mlx->img.exit = mlx_xpm_file_to_image(mlx->mlx, "./xpm/exit.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.exit)
		ft_putendl_fd("EXIT : fail", 2);
	mlx->img.position = mlx_xpm_file_to_image(mlx->mlx, "./xpm/position.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.position)
		ft_putendl_fd("POSITION : fail", 2);
}

void	build_map(t_vars *mlx, t_map *map, t_vars lenght)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != '\0')
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (read_map(*mlx, map->map[i][j],
				i * lenght.lenght, j * lenght.lenght) == 1)
			{
				map->pos_x = i;
				map->pos_y = j;
			}
			j++;
		}
		i++;
	}
}

int	co_x(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[0][i])
	{
		i++;
	}
	j = i * 44;
	return (j);
}

int	co_y(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		i++;
	}
	j = i * 44;
	return (j);
}
