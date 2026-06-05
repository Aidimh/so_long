/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:28:57 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/26 23:19:12 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <mlx.h>
//# include "./minilibx-linux/mlx.h"

# define SCREEN_WIDTH
# define SCREEN_HEIGHT

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*collectible_img;
	void	*wall_img;
	void	*exit_img;
	void	*blank_img;
	char	**map_file;
	char	**copy;
	char	*line;
	int		fd;
	int		i;
	int		j;
	int		len;
	int		win_hig;
	int		win_wid;
	int		screen_hig;
	int		screen_wid;
	int		player;
	int		exit;
	int		collectibles;
	int		blank;
	int		walls;
	int		rows;
	int		cols;
	int		img_height;
	int		img_width;
	int		player_x;
	int		player_y;
	int		collected;
	int		moves;
	int		x;
	int		y;
}			t_vars;

void		validate_map(t_vars *vars);
void		initialize_game(t_vars *vars);
void		exit_error_for_map(int exit_value, t_vars *vars);
void		exit_error_for_map1(int exit_value, t_vars *vars);
char		**read_map(char *file_name, t_vars *vars);
void		free_map(t_vars *vars);
void		free_copy(t_vars *vars);
void		get_measures(t_vars *vars);
void		exit_error_for_map2(int exit_value, t_vars *vars);
int			check_for_stranger_elements(char c);
void		count_map_elements(t_vars *vars);
void		load_all_images(t_vars *vars);
void		to_right(int x, int y, t_vars *vars);
void		free_mlx(t_vars *vars);
void		validate_path(t_vars *vars);
void		find_player_position(t_vars *vars);
int			close_window(void *param);
void		exit_error_for_map3(int exit_value, t_vars *vars);
void		is_valid_ber_map(char *map_name, t_vars *vars);
#endif
