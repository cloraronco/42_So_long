/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:02:16 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/05 18:03:43 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall_hori(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = count_line_verti(map) - 1;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			return (0);
		j++;
	}
	while (map->map[k][i])
	{
		if (map->map[k][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_wall_verti(t_map *map)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(map->map[0]) - 1;
	while (i < count_line_verti(map))
	{
		if (map->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < count_line_verti(map))
	{
		if (map->map[i][k] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_exit_player(t_map *map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
				exit++;
			if (map->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (exit < 1 || player != 1)
		return (0);
	return (1);
}

int	check_map_coin(t_map *map)
{
	int	i;
	int	j;
	int	coin;

	i = 0;
	coin = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				coin++;
			j++;
		}
		i++;
	}
	if (coin < 1)
		return (0);
	return (1);
}

void	check_map(t_vars *mlx, t_map *map)
{
	if (check_map_hori(map) == 0 || check_map_verti(map) == 0)
		ft_close_error(mlx);
	if (check_map_wall_hori(map) == 0 || check_map_wall_verti(map) == 0)
		ft_close_error(mlx);
	if (check_map_exit_player(map) == 0 || check_map_coin(map) == 0)
		ft_close_error(mlx);
	if (check_geo(map) == 1)
		ft_close_error(mlx);
}
