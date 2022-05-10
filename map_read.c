/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:42:46 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/09 09:03:43 by clora-ro         ###   ########lyon.fr   */
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

int	load_image(t_vars *mlx, t_vars lenght)
{
	mlx->img.wall = mlx_xpm_file_to_image(mlx->mlx, "./xpm/wall.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.wall)
		return (ft_close_error1(mlx));
	mlx->img.floor = mlx_xpm_file_to_image(mlx->mlx, "./xpm/floor.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.floor)
		return (ft_close_error2(mlx));
	mlx->img.piece = mlx_xpm_file_to_image(mlx->mlx, "./xpm/piece.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.piece)
		return (ft_close_error3(mlx));
	mlx->img.exit = mlx_xpm_file_to_image(mlx->mlx, "./xpm/exit.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.exit)
		return (ft_close_error4(mlx));
	mlx->img.position = mlx_xpm_file_to_image(mlx->mlx, "./xpm/position.xpm",
			&lenght.lenght, &lenght.lenght);
	if (!mlx->img.position)
		return (ft_close_error5(mlx));
	return (0);
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
