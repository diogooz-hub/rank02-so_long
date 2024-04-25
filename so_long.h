/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:58:13 by dpaco             #+#    #+#             */
/*   Updated: 2024/02/06 22:11:37 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../so_long/mlx_linux/mlx.h"
# include "../so_long/libft/headers/libft.h"
# include "../so_long/libft/headers/get_next_line.h"
# include "../so_long/libft/headers/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

# define W 119
# define A 97
# define S 115
# define D 100

# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

# define ESC 65307

typedef struct t_data
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		y_axis_prev;
	int		x_axis_prev;
	int		counter;
	int		collectables;

	char	**map;
	char	**map_check;
	char	prev_pos;
	char	next_move;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*exit_x;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_data;

// Map
void	map_reading(t_data *game, char **argv);

// Build
void	images_for_game(t_data *game);
void	build_map(t_data *game);
void	update_map(t_data *game);

// Checks
void	validate_map(t_data *game);
//fill
void	playable_game(t_data *game);

// Controls
int		key_mapping(int key, t_data *game);

// Errors and Exit
void	exit_error(char *s, t_data *game);
int		exit_game(t_data *game);

#endif