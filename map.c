/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:54:57 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/18 23:53:47 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_rows(t_data *game)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		row++;
		if (*line == '\n')
		{
			free(line);
			exit_error("error reading - check the map", game);
		}
		free(line);
		line = get_next_line(game->fd);
	}
	if (row == 0)
		exit_error("error 2 reading - check the map", game);
	else
		game->heightmap = row;
	free(line);
}

static void	map_array(t_data *game)
{
	char	*line;
	int		row;

	game->map = (char **)malloc((sizeof(char *) * (game->heightmap + 1)));
	game->map_check = (char **)malloc((sizeof(char *) * (game->heightmap + 1)));
	if (!game->map || !game->map_check)
		exit_error("Error on malloc for map array", game);
	row = 0;
	line = get_next_line(game->fd);
	while (row < game->heightmap)
	{
		game->map[row] = ft_strtrim(line, "\n");
		game->map_check[row] = ft_strtrim(line, "\n");
		free(line);
		row++;
		line = get_next_line(game->fd);
	}
	game->map[row] = NULL;
	game->map_check[row] = NULL;
	game->widthmap = ft_strlen(game->map[game->heightmap - 1]);
}

void	map_reading(t_data *game, char **av)
{
	game->fd = open(av[1], O_RDONLY);
	map_rows(game);
	close(game->fd);
	game->fd = open(av[1], O_RDONLY);
	map_array(game);
	close(game->fd);
}
