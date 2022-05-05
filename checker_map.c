/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:02:58 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/05 17:34:45 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_hori(t_map *map)
{
	int	i;
	int	k;
	int	size;

	k = 0;
	while (map->map[k])
	{
		size = ft_strlen(map->map[k]);
		i = 0;
		while (map->map[i])
		{
			if (ft_strlen(map->map[i]) != size)
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}

int	count_line_verti(t_map *map)
{
	int	j;

	j = 0;
	while (map->map[j])
		j++;
	return (j);
}

int	check_map_verti(t_map *map)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	while (map->map[0][j])
	{
		size = count_line_verti(map);
		i = 0;
		while (map->map[0][i])
		{
			if (count_line_verti(map) != size)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_geo(t_map *map)
{
	if (ft_strlen(map->map[0]) != count_line_verti(map))
		return (0);
	return (1);
}

// int check_map_element(t_map *map)
// {
// 	if (NULL < 3)
// 		return (0);
// 	return (1);
// }
