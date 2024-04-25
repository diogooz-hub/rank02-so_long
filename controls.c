/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:30:50 by dpaco             #+#    #+#             */
/*   Updated: 2024/04/02 21:13:45 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_move(t_data *game, int row, int col)
{
	if (game->map[row][col] == 'E' && game->collectables == 0)
	{
		printf("\nYOU HAVE WON THIS STUPID GAME\n");
		exit_game(game);
	}
	if (game->map[row][col] == '1')
		return (0);
	if (game->map[row][col] == 'C')
	{
		game->collectables--;
		printf("Collectables left: %i\n", game->collectables);
	}
	return (1);
}

static void	update_player_pos(t_data *game, int row, int col)
{
	game->map[row][col] = 'P';
	game->y_axis = row;
	game->x_axis = col;
	game->counter++;
	if (game->next_move == 'C')
		game->prev_pos = '0';
	else
		game->prev_pos = game->next_move;
}

static int	move_player(t_data *game, int dx, int dy)
{
	int	row;
	int	col;

	row = game->y_axis + dy;
	col = game->x_axis + dx;
	game->y_axis_prev = game->y_axis;
	game->x_axis_prev = game->x_axis;
	game->next_move = game->map[row][col];
	if (!is_valid_move(game, row, col))
		return (0);
	game->map[row - dy][col - dx] = game->prev_pos;
	update_player_pos(game, row, col);
	return (1);
}

static int	keyboard_move(t_data *game, int key)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (key == W || key == ARROW_UP)
		dy = -1;
	else if (key == S || key == ARROW_DOWN)
		dy = 1;
	else if (key == A || key == ARROW_LEFT)
		dx = -1;
	else if (key == D || key == ARROW_RIGHT)
		dx = 1;
	return (move_player(game, dx, dy));
}

int	key_mapping(int key, t_data *game)
{
	int	works;

	works = 0;
	if (key == ESC)
		exit_game(game);
	else if (key == W || key == ARROW_UP || key == S || key == ARROW_DOWN || 
		key == A || key == ARROW_LEFT || key == D || key == ARROW_RIGHT)
		works = keyboard_move(game, key);
	if (works)
	{
		printf("Steps Taken: %i\n", game->counter);
		if (game->collectables == 0)
			build_map(game);
		else
			update_map(game);
	}
	return (1);
}

/*
int key_mapping(int key, t_data *game)
{
    printf("Pressed key: %d\n", key);
    return (0);
}
*/
