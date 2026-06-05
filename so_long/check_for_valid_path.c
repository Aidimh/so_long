/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:53:50 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/24 01:54:24 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdbool.h>
#include <stdio.h>

void	initilaize_vars(int	*i, int	*exit_found)
{
	*i = 0;
	*exit_found = 0;
}

void	duplicate_map(t_vars *vars)
{
	int	y;
	int	x;

	vars->copy = malloc(sizeof(char *) * 100);
	if (!vars->copy)
	{
		free_map(vars);
		free(vars);
		return ;
	}
	y = 0;
	while (vars->map_file[y])
	{
		x = 0;
		vars->copy[y] = malloc(sizeof(char) * (ft_strlen(vars->map_file[y])
					+ 1));
		while (vars->map_file[y][x])
		{
			vars->copy[y][x] = vars->map_file[y][x];
			x++;
		}
		vars->copy[y][x] = '\0';
		y++;
	}
	vars->copy[y] = NULL;
}

void	flood_fill(t_vars *vars, int y, int x)
{
	if (y < 0 || y >= vars->rows || x < 0 || x >= vars->cols)
		return ;
	if (vars->copy[y][x] == '1' || vars->copy[y][x] == 'F')
		return ;
	else if (vars->copy[y][x] == 'E')
	{
		vars->copy[y][x] = 'F';
		return ;
	}
	vars->copy[y][x] = 'F';
	flood_fill(vars, y - 1, x);
	flood_fill(vars, y + 1, x);
	flood_fill(vars, y, x - 1);
	flood_fill(vars, y, x + 1);
}

int	if_map_is_valid(t_vars *vars)
{
	int	x;
	int	y;
	int	exit_found;

	initilaize_vars(&y, &exit_found);
	while (y < vars->rows)
	{
		x = 0;
		while (x < vars->cols)
		{
			if (vars->map_file[y][x] == 'C')
			{
				if (vars->copy[y][x] != 'F')
					return (0);
			}
			if (vars->map_file[y][x] == 'E')
			{
				if (vars->copy[y][x] == 'F')
					exit_found = 1;
			}
			x++;
		}
		y++;
	}
	return (exit_found);
}

void	validate_path(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	duplicate_map(vars);
	flood_fill(vars, y, x);
	if (!(if_map_is_valid(vars)))
		exit_error_for_map3(11, vars);
	else
	{
		free_copy(vars);
		free(vars->copy);
	}
	return ;
}
