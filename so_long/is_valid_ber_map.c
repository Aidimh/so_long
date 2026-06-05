/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ber_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:50:10 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/24 16:50:18 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	is_valid_ber_map(char *map_name, t_vars *vars)
{
	char	*extension;

	extension = ft_strchr(map_name, '.');
	if (!extension || ft_strcmp(extension, ".ber") != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Not a valid .ber file\n", 2);
		free(vars);
		exit(1);
	}
	return ;
}
