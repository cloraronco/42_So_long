/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:11 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/05 15:19:54 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	first_position(t_map map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map.map || map.map[x][y] != 'P')
	{
		y = 0;
		while (map.map[x][y] != '\n' || map.map[x][y] != 'P')
			y++;
		x++;
	}
	return (map.map[x][y]);
}

void	change_map(t_vars *mlx, t_map *map)
{
	if (mlx->up == 1)
	{
		move_up(mlx, map);
		map->pos_x -= 1;
		count_move(1);
	}
	if (mlx->down == 1)
	{
		move_down(mlx, map);
		map->pos_x += 1;
		count_move(1);
	}
	if (mlx->left == 1)
	{
		move_left(mlx, map);
		map->pos_y -= 1;
		count_move(1);
	}
	if (mlx->right == 1)
	{
		move_right(mlx, map);
		map->pos_y += 1;
		count_move(1);
	}
}
