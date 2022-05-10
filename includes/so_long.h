/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:55:00 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/09 10:19:54 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		pos_x;
	int		pos_y;
}	t_map;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*piece;
	void	*position;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	t_img	img;
	void	*win;
	char	*move;
	t_map	*map;
	int		lenght;
	int		up;
	int		down;
	int		left;
	int		right;
}	t_vars;

int		main(int ac, char **av);

void	init_mlx(t_vars *mlx);
void	ft_free_split(char **tab);
int		count_line(char *av);
void	replace_backline(char *str);
void	init_map(char *av, t_map *map);

int		read_map(t_vars mlx, char c, int x, int y);
int		load_image(t_vars *mlx, t_vars lenght);
void	build_map(t_vars *mlx, t_map *map, t_vars lenght);
int		co_x(t_map *map);
int		co_y(t_map *map);

int		my_key_code(int keycode, t_vars *mlx);
void	ft_close(t_vars *mlx);
int		ft_close_hook(t_vars *mlx);
void	ft_close_error(t_vars *mlx);
void	events_hooks(t_vars *mlx);

char	first_position(t_map map);
void	change_map(t_vars *mlx, t_map *map);

int		check_wall_up(t_map *map);
int		check_wall_down(t_map *map);
int		check_wall_left(t_map *map);
int		check_wall_right(t_map *map);
void	count_move(int i);

int		check_map_wall_hori(t_map *map);
int		check_map_wall_verti(t_map *map);
int		check_map_exit_player(t_map *map);
int		check_map_coin(t_map *map);
void	check_map(t_vars *mlx, t_map *map);

int		check_name(char *av, t_map *map);
int		check_map_hori(t_map *map);
int		count_line_verti(t_map *map);
int		check_map_verti(t_map *map);
int		check_geo(t_map *map);

int		check_map_char(t_map *map);
void	move_up(t_vars *mlx, t_map *map);
void	move_down(t_vars *mlx, t_map *map);
void	move_left(t_vars *mlx, t_map *map);
void	move_right(t_vars *mlx, t_map *map);

int		ft_close_error1(t_vars *mlx);
int		ft_close_error2(t_vars *mlx);
int		ft_close_error3(t_vars *mlx);
int		ft_close_error4(t_vars *mlx);
int		ft_close_error5(t_vars *mlx);

#endif