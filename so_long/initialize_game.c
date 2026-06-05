/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:05:33 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/24 02:25:29 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->map_file)
		free_map(vars);
	free_mlx(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
}

void	render_map(t_vars *vars)
{
	while (vars->map_file[vars->x])
	{
		vars->y = 0;
		while (vars->map_file[vars->x][vars->y])
		{
			if (vars->map_file[vars->x][vars->y] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img,
					vars->y * 50, vars->x * 50);
			else if (vars->map_file[vars->x][vars->y] == '0')
				mlx_pixel_put(vars->mlx, vars->win, vars->y * 50, vars->x * 50,
					0x000000);
			else if (vars->map_file[vars->x][vars->y] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->collectible_img, vars->y * 50, vars->x * 50);
			else if (vars->map_file[vars->x][vars->y] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img,
					vars->y * 50, vars->x * 50);
			else if (vars->map_file[vars->x][vars->y] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player_img,
					vars->y * 50, vars->x * 50);
			vars->y++;
		}
		vars->x++;
	}
}

void	process_move(t_vars *vars, int new_x, int new_y)
{
	if (vars->map_file[new_y][new_x] == 'C')
	{
		vars->collected++;
		vars->map_file[new_y][new_x] = '0';
	}
	else if (vars->map_file[new_y][new_x] == 'E')
	{
		ft_putstr_fd("Current Moves count is : ", 1);
		ft_putnbr_fd(++vars->moves, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("You win!\n", 1);
		close_window(vars);
	}
	vars->map_file[vars->player_y][vars->player_x] = '0';
	vars->map_file[new_y][new_x] = 'P';
	vars->player_x = new_x;
	vars->player_y = new_y;
	ft_putstr_fd("Current Moves count is : ", 1);
	ft_putnbr_fd(++vars->moves, 1);
	ft_putstr_fd("\n", 1);
	mlx_clear_window(vars->mlx, vars->win);
	vars->x = 0;
	vars->y = 0;
	render_map(vars);
}

int	handle_keypress(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x;
	new_y = vars->player_y;
	if (keycode == 65307)
		return (close_window(vars));
	else if (keycode == 97 || keycode == 65361)
		new_x -= 1;
	else if (keycode == 100 || keycode == 65363)
		new_x += 1;
	else if (keycode == 119 || keycode == 65362)
		new_y -= 1;
	else if (keycode == 115 || keycode == 65364)
		new_y += 1;
	else
		return (0);
	if (vars->map_file[new_y][new_x] == '1' ||
		(vars->map_file[new_y][new_x] == 'E' &&
		vars->collected != vars->collectibles))
		return (0);
	process_move(vars, new_x, new_y);
	return (0);
}

void	initialize_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit_error_for_map2(7, vars);
	vars->win_wid = vars->cols * 50;
	vars->win_hig = vars->rows * 50;
	mlx_get_screen_size(vars->mlx, &vars->screen_wid, &vars->screen_hig);
	if ((vars->win_wid >= vars->screen_wid)
		|| (vars->win_hig >= vars->screen_hig))
		exit_error_for_map2(10, vars);
	vars->win = mlx_new_window(vars->mlx, (vars->cols * 50), (vars->rows * 50),
			"so_long");
	if (!vars->win)
		exit_error_for_map3(12, vars);
	load_all_images(vars);
	render_map(vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_key_hook(vars->win, handle_keypress, vars);
	mlx_loop(vars->mlx);
}
