/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:29:53 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/09 10:26:19 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!(map->map[i][j] == '1' || map->map[i][j] == '0'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'P'
				|| map->map[i][j] == 'C'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	move_up(t_vars *mlx, t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x - 1][y] == 'E' && check_map_coin(map) == 0)
		ft_close(mlx);
	if (map->map[x - 1][y] == '0' || map->map[x - 1][y] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.floor, y * 44,
			x * 44);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.position, y * 44,
			(x - 1) * 44);
		map->map[x][y] = '0';
		map->map[x - 1][y] = 'P';
	}
	mlx->up = 0;
}

void	move_down(t_vars *mlx, t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x + 1][y] == 'E' && check_map_coin(map) == 0)
		ft_close(mlx);
	if (map->map[x + 1][y] == '0' || map->map[x + 1][y] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.floor, y * 44,
			x * 44);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.position, y * 44,
			(x + 1) * 44);
		map->map[x][y] = '0';
		map->map[x + 1][y] = 'P';
	}
	mlx->down = 0;
}

void	move_left(t_vars *mlx, t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x][y - 1] == 'E' && check_map_coin(map) == 0)
		ft_close(mlx);
	if (map->map[x][y - 1] == '0' || map->map[x][y - 1] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.floor, y * 44,
			x * 44);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.position,
			(y - 1) * 44, x * 44);
		map->map[x][y] = '0';
		map->map[x][y - 1] = 'P';
	}
	mlx->left = 0;
}

void	move_right(t_vars *mlx, t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x][y + 1] == 'E' && check_map_coin(map) == 0)
		ft_close(mlx);
	if (map->map[x][y + 1] == '0' || map->map[x][y + 1] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.floor, y * 44,
			x * 44);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.position,
			(y + 1) * 44, x * 44);
		map->map[x][y] = '0';
		map->map[x][y + 1] = 'P';
	}
	mlx->right = 0;
}
