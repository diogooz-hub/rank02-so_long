/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:55:15 by dpaco             #+#    #+#             */
/*   Updated: 2024/04/02 19:45:12 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_data *game)
{
	game->fd = 0;
	game->heightmap = 0;
	game->widthmap = 0;
	game->playercount = 0;
	game->exitcount = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->x_axis_prev = 0;
	game->y_axis_prev = 0;
	game->counter = 0;
	game->collectables = 0;
	game->prev_pos = '0';
	game->next_move = '0';
	game->map = NULL;
	game->map_check = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->exit_x = NULL;
}

static void	check_args(t_data *game, int argc, char **argv)
{
	if (argc != 2)
		exit_error("Invalid number of arguments.", game);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		exit_error("File must be of type .ber", game);
}

int	main(int ac, char **av)
{
	t_data	game;

	check_args(&game, ac, av);
	init_struct(&game);
	map_reading(&game, av);
	validate_map(&game);
	playable_game(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, game.widthmap * 40, 
			game.heightmap * 40, "so_long");
	images_for_game(&game);
	build_map(&game);
	mlx_key_hook(game.winpointer, key_mapping, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit_game, &game);
	mlx_loop(game.mlxpointer);
	return (0);
}
