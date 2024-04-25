/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:42:36 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/18 23:47:49 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_data *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

static void	free_map_check(t_data *game)
{
	int	i;

	if (!game->map_check)
		return ;
	i = 0;
	while (game->map_check[i])
	{
		free(game->map_check[i]);
		i++;
	}
	free(game->map_check);
	game->map_check = NULL;
}

void	exit_error(char *s, t_data *game)
{
	if (s != NULL)
		ft_printf("Error\n%s\n", s);
	if (game->map != NULL)
		free_map(game);
	if (game->map_check != NULL)
		free_map_check(game);
	exit(1);
}

int	exit_game(t_data *game)
{
	if (game->player)
		mlx_destroy_image(game->mlxpointer, game->player);
	if (game->floor)
		mlx_destroy_image(game->mlxpointer, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlxpointer, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlxpointer, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlxpointer, game->collectable);
	if (game->exit_x)
		mlx_destroy_image(game->mlxpointer, game->exit_x);
	mlx_destroy_window(game->mlxpointer, game->winpointer);
	free_map(game);
	free_map_check(game);
	mlx_destroy_display(game->mlxpointer);
	free(game->mlxpointer);
	exit(0);
}
