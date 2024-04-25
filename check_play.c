/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:53:38 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/19 00:26:28 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	fill(t_data *game, char start, int row, int col)
{
	static bool	exit;
	static int	c_check;

	if (row < 0 || col < 0 || row >= game->heightmap || col >= game->widthmap)
		return (false);
	else if (game->map_check[row][col] == 'F')
		return (false);
	else if (game->map_check[row][col] == '1')
		return (false);
	else if (game->map_check[row][col] == 'E')
		exit = true;
	if (game->map_check[row][col] == 'C')
		c_check++;
	game->map_check[row][col] = 'F';
	fill(game, start, row + 1, col);
	fill(game, start, row, col + 1);
	fill(game, start, row - 1, col);
	fill(game, start, row, col - 1);
	return (c_check == game->collectables && exit);
}

void	playable_game(t_data *game)
{
	char	start;
	int		row;
	int		col;
	bool	map_valid;

	start = game->map_check[game->y_axis][game->x_axis];
	row = game->y_axis;
	col = game->x_axis;
	map_valid = fill(game, start, row, col);
	if (!map_valid)
		exit_error("Game is not playable", game);
}
