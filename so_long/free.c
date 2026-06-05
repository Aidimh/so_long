/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:27:53 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/24 15:32:25 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(t_vars *vars)
{
	int	i;

	if (!vars || !vars->map_file)
		return ;
	i = 0;
	while (vars->map_file[i])
	{
		free(vars->map_file[i]);
		i++;
	}
	free(vars->map_file);
	vars->map_file = NULL;
}

void	free_copy(t_vars *vars)
{
	int	i;

	if (!vars || !vars->copy)
		return ;
	i = 0;
	while (vars->copy[i])
	{
		free(vars->copy[i]);
		i++;
	}
	free(vars->copy);
	vars->copy = NULL;
}

void	free_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player_img);
	mlx_destroy_image(vars->mlx, vars->wall_img);
	mlx_destroy_image(vars->mlx, vars->collectible_img);
	mlx_destroy_image(vars->mlx, vars->exit_img);
}
