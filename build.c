/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:55:02 by dpaco             #+#    #+#             */
/*   Updated: 2024/04/02 19:45:08 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_for_game(t_data *game)
{
	int	size;

	size = 40;
	game->floor = mlx_xpm_file_to_image(game->mlxpointer, 
			"game_imgs/floor.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer, 
			"game_imgs/wall.xpm", &size, &size);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_imgs/collectable.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_imgs/player.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_imgs/exit.xpm", &size, &size);
	game->exit_x = mlx_xpm_file_to_image(game->mlxpointer,
			"game_imgs/floorx.xpm", &size, &size);
}

static void	place_images(t_data *game, char c, int row, int col)
{
	int	size;

	size = 40;
	if (c == '1')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->wall, col * size, row * size);
	else if (c == '0')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->floor, col * size, row * size);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->player, col * size, row * size);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->exit, col * size, row * size);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->collectable, col * size, row * size);
	else if (c == 'X')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->exit_x, col * size, row * size);
}

static void	change_exit(t_data *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'X')
				game->map[row][col] = 'E';
			col++;
		}
		row++;
	}
}

void	build_map(t_data *game)
{
	int	row;
	int	col;

	if (game->collectables == 0)
		change_exit(game);
	row = 0;
	while (row < game->heightmap)
	{
		col = 0;
		while (col < game->widthmap)
		{
			place_images(game, game->map[row][col], row, col);
			col++;
		}
		row++;
	}
}

void	update_map(t_data *game)
{
	place_images(game, 'P', game->y_axis, game->x_axis);
	place_images(game, game->prev_pos, game->y_axis_prev, game->x_axis_prev);
}
