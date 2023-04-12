/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:23 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/12 16:13:35 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	tracker_reset(t_data *data)
{
	data->track_c = 0;
	data->track_e = 0;
	data->track_p = 0;
}

void	free_textures(t_game *game)
{
	if (game->world.grass)
		mlx_delete_texture(game->world.grass);
	if (game->world.water)
		mlx_delete_texture(game->world.water);
	if (game->world.collectible)
		mlx_delete_texture(game->world.collectible);
	if (game->world.exit)
		mlx_delete_texture(game->world.exit);
	if (game->player.pmodel)
		mlx_delete_texture(game->player.pmodel);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	free_textures(game);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_game		game;

	errno = 0;
	if (argc != 2)
		error(ERR_INPUT);
	else if (file_check(argv[1]))
		error(ERR_FT);
	game = init_game();
	open_map(argv[1], &game.map);
	tracker_reset(&data);
	validate_map(&game.map, &data);
	copy_player_data(&game);
	build_game(game);
	free_game(&game);
	return (0);
}
