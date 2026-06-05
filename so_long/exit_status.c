/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:27:49 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/26 20:39:29 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	close_error(t_vars *vars)
{
	free(vars->copy);
	if (vars->map_file)
		free_map(vars);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->win);
}

void	exit_error_for_map(int exit_value, t_vars *vars)
{
	if (exit_value == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is not surrounded by walls\n", 2);
	}
	else if (exit_value == 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid character in map !\n", 2);
	}
	else if (exit_value == 3)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid map format\n", 2);
	}
	free_map(vars);
	free(vars);
	exit(1);
}

void	exit_error_for_map1(int exit_value, t_vars *vars)
{
	if (exit_value == 4)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is not rectangular !\n", 2);
	}
	else if (exit_value == 5)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map must contain 1 player and 1 exit,", 2);
		ft_putstr_fd("and at least 1 collectible\n", 2);
	}
	else if (exit_value == 6)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		free(vars);
		exit(1);
	}
	free_map(vars);
	free(vars);
	exit(1);
}

void	exit_error_for_map2(int exit_value, t_vars *vars)
{
	if (exit_value == 7)
	{
		free_map(vars);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("mlx_init failed\n", 2);
	}
	else if (exit_value == 8)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to open map file. may not exist\n", 2);
	}
	else if (exit_value == 9)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map allocation failed\n", 2);
	}
	else if (exit_value == 10)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is too large\n", 2);
		free_copy(vars);
		close_error(vars);
	}
	free(vars);
	exit(1);
}

void	exit_error_for_map3(int exit_value, t_vars *vars)
{
	if (exit_value == 11)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid map : collectibles or exit are not reachable\n",
			2);
		free_map(vars);
		free_copy(vars);
		close_error(vars);
		free(vars);
		exit(1);
	}
	if (exit_value == 12)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("failed to load map, might be empty\n", 2);
		free_map(vars);
		free(vars);
		exit(1);
	}
}
