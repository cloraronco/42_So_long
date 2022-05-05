/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:05:06 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/05 17:59:34 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_up(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x - 1][y] == '1')
		return (0);
	if (map->map[x - 1][y] == 'E' && check_map_coin(map) == 1)
		return (0);
	return (1);
}

int	check_wall_down(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x + 1][y] == '1')
		return (0);
	if (map->map[x + 1][y] == 'E' && check_map_coin(map) == 1)
		return (0);
	return (1);
}

int	check_wall_left(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x][y - 1] == '1')
		return (0);
	if (map->map[x][y - 1] == 'E' && check_map_coin(map) == 1)
		return (0);
	return (1);
}

int	check_wall_right(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->map[x][y + 1] == '1')
		return (0);
	if (map->map[x][y + 1] == 'E' && check_map_coin(map) == 1)
		return (0);
	return (1);
}

void	count_move(int i)
{
	static int	count;

	count = i + count;
	ft_putnbr_fd(count, 2);
	ft_putendl_fd("", 2);
}
