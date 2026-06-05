/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:30 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/23 23:24:22 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_for_rectangle(t_vars *vars)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	flag = vars->cols;
	while (vars->map_file[i])
	{
		len = ft_strlen(vars->map_file[i]);
		if (flag != len)
			exit_error_for_map1(4, vars);
		i++;
	}
	return (0);
}

int	check_for_stranger_elements(char c)
{
	char	*map_element;
	int		seen;
	int		i;

	i = 0;
	seen = 0;
	map_element = "10EPC";
	while (map_element[i])
	{
		if (map_element[i] == c)
			seen++;
		i++;
	}
	return (seen);
}

void	count_map_elements(t_vars *vars)
{
	int	i;
	int	x;

	x = 0;
	while (vars->map_file[x])
	{
		i = 0;
		while (vars->map_file[x][i])
		{
			if (vars->map_file[x][i] == 'P')
				vars->player++;
			else if (vars->map_file[x][i] == 'C')
				vars->collectibles++;
			else if (vars->map_file[x][i] == 'E')
				vars->exit++;
			else if (vars->map_file[x][i] == '0')
				vars->blank++;
			else if (vars->map_file[x][i] == '1')
				vars->walls++;
			else if (!(check_for_stranger_elements(vars->map_file[x][i])))
				exit_error_for_map(2, vars);
			i++;
		}
		x++;
	}
}

void	check_for_walls(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->cols)
	{
		if (vars->map_file[0][i] != '1' || vars->map_file[vars->rows
			- 1][i] != '1')
			exit_error_for_map(1, vars);
		i++;
	}
	i = 0;
	while (i < vars->rows)
	{
		if ((vars->map_file[i][0] != '1') || (vars->map_file[i][vars->cols
				- 1] != '1'))
			exit_error_for_map(1, vars);
		i++;
	}
}

void	validate_map(t_vars *vars)
{
	vars->player = 0;
	vars->exit = 0;
	vars->collectibles = 0;
	if (vars->rows >= vars->cols)
		exit_error_for_map1(4, vars);
	if (check_for_rectangle(vars))
		exit_error_for_map1(4, vars);
	check_for_walls(vars);
	count_map_elements(vars);
	if (vars->player != 1 || vars->exit != 1 || vars->collectibles < 1)
		exit_error_for_map1(5, vars);
	return ;
}
