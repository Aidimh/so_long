/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:32:05 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/24 15:32:09 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	load_player_image(t_vars *vars)
{
	vars->player_img = mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->player_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to load player image\n", 2);
		free_map(vars);
		free(vars);
		exit(1);
	}
}

void	load_collectibles_image(t_vars *vars)
{
	vars->collectible_img = mlx_xpm_file_to_image(vars->mlx,
			"textures/collect.xpm", &vars->img_width, &vars->img_height);
	if (!vars->collectible_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to load collectible image\n", 2);
		free_map(vars);
		free(vars);
		exit(1);
	}
}

void	load_walls_image(t_vars *vars)
{
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->wall_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to load wall image\n", 2);
		free_map(vars);
		free(vars);
		exit(1);
	}
}

void	load_exit_image(t_vars *vars)
{
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->exit_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to load exit image\n", 2);
		free_map(vars);
		free(vars);
		exit(1);
	}
}

void	load_all_images(t_vars *vars)
{
	load_player_image(vars);
	load_walls_image(vars);
	load_collectibles_image(vars);
	load_exit_image(vars);
}
