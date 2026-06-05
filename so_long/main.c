/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:31 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/24 15:45:13 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"
#include "so_long.h"
#include <stdio.h>

void	find_player_position(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map_file[y])
	{
		x = 0;
		while (vars->map_file[y][x])
		{
			if (vars->map_file[y][x] == 'P')
			{
				vars->player_x = x;
				vars->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	process_line(char *line, t_vars *vars)
{
	vars->len = ft_strlen(line);
	if (vars->len > 0 && line[vars->len - 1] == '\n')
		line[vars->len - 1] = '\0';
	if (line[0] != '\0')
		vars->map_file[vars->i++] = line;
	else
		free(line);
}

char	**read_map(char *file_name, t_vars *vars)
{
	char	*line;

	vars->fd = open(file_name, O_RDONLY);
	if (vars->fd < 0)
		exit_error_for_map2(8, vars);
	vars->map_file = malloc(sizeof(char *) * 100);
	if (!vars->map_file)
		exit_error_for_map2(9, vars);
	vars->i = 0;
	line = get_next_line(vars->fd);
	while (line)
	{
		process_line(line, vars);
		line = get_next_line(vars->fd);
	}
	vars->map_file[vars->i] = NULL;
	close(vars->fd);
	return (vars->map_file);
}

void	get_measures(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_file[i])
		i++;
	vars->rows = i;
	i = 0;
	while (vars->map_file[0][i])
		i++;
	find_player_position(vars);
	vars->cols = i;
	vars->img_height = 50;
	vars->img_width = 50;
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		exit(1);
	ft_bzero(vars, sizeof(t_vars));
	if (ac >= 2 && ac > 2)
		exit_error_for_map1(6, vars);
	if (!av[1])
		exit_error_for_map1(6, vars);
	is_valid_ber_map(av[1], vars);
	vars->map_file = read_map(av[1], vars);
	if (!vars->map_file[0])
		exit_error_for_map3(12, vars);
	get_measures(vars);
	if (vars->rows == vars->cols)
		exit_error_for_map1(4, vars);
	validate_map(vars);
	validate_path(vars);
	initialize_game(vars);
	return (0);
}
