/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:54:33 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/09 08:14:02 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_mlx(t_vars *mlx)
{
	mlx->up = 0;
	mlx->down = 0;
	mlx->left = 0;
	mlx->right = 0;
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_line(char *av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

void	replace_backline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	str[i] = '\0';
}

void	init_map(char *av, t_map *map)
{
	int	fd;
	int	i;
	int	nb_line;

	nb_line = count_line(av);
	fd = open(av, O_RDONLY);
	i = 0;
	map->map = ft_calloc((nb_line + 1), sizeof(char *));
	while (i < nb_line)
	{
		map->map[i] = get_next_line(fd);
		if (i < nb_line)
			replace_backline(map->map[i]);
		if (!map->map[i])
		{
			ft_free_split(map->map);
			close(fd);
			exit(1);
		}
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}
