/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:35:25 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/19 00:25:53 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(t_data *game, char c, int row, int col)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
	{
		if (c == 'P')
		{
			game->playercount++;
			game->x_axis = col;
			game->y_axis = row;
		}
		else if (c == 'E')
		{
			game->map[row][col] = 'X';
			game->exitcount++;
		}
		else if (c == 'C')
			game->collectables++;
	}
	else
		exit_error("Bro, there is a random char on the map", game);
}

static void	map_elements(t_data *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			check_char(game, game->map[row][col], row, col);
			col++;
		}
		row++;
	}
	if (game->playercount != 1)
		exit_error("No player, or more than one? go check", game);
	else if (game->collectables == 0)
		exit_error("No collectables to have fun", game);
	else if (game->exitcount == 0)
		exit_error("No exit to leave man", game);
	else if (game->exitcount > 1)
		exit_error("Too many exits, its confusing", game);
}

static void	check_walls(t_data *game)
{
	int	col;
	int	row;

	col = 0;
	while (col < game->widthmap)
	{
		if (game->map[0][col] != '1')
			exit_error("Up wall is fucked up", game);
		if (game->map[game->heightmap - 1][col] != '1')
			exit_error("Down wall is fucked up", game);
		col++;
	}
	row = 0;
	while (row < game->heightmap)
	{
		if (game->map[row][0] != '1')
			exit_error("Left wall is fucked up", game);
		if (game->map[row][game->widthmap - 1] != '1')
			exit_error("Right wall is fucked up", game);
		row++;
	}
}

void	validate_map(t_data *game)
{
	map_elements(game);
	check_walls(game);
}
