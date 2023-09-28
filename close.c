/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:49:32 by clora-ro          #+#    #+#             */
/*   Updated: 2022/05/09 09:05:47 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_error1(t_vars *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putendl_fd("WALL : fail\nError", 2);
	exit(1);
	return (1);
}

int	ft_close_error2(t_vars *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putendl_fd("FLOOR : fail\nError", 2);
	exit(1);
	return (1);
}

int	ft_close_error3(t_vars *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.floor);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putendl_fd("PIECE : fail\nError", 2);
	exit(1);
	return (1);
}

int	ft_close_error4(t_vars *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.floor);
	mlx_destroy_image(mlx->mlx, mlx->img.piece);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putendl_fd("EXIT : fail\nError", 2);
	exit(1);
	return (1);
}

int	ft_close_error5(t_vars *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.floor);
	mlx_destroy_image(mlx->mlx, mlx->img.piece);
	mlx_destroy_image(mlx->mlx, mlx->img.exit);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putendl_fd("POSITION : fail\nError", 2);
	exit(1);
	return (1);
}
