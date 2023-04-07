/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:28:39 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/07 20:11:02 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

static void	place_player(t_game *game)
{
	mlx_texture_t	*character;

	character = mlx_load_png("./textures/Barrel.png");
	game->player.img = mlx_texture_to_image(game->mlx, character);
}

// static void	create_collect(t_game *game)
// {
// 	int				xi;
// 	int				yi;
// 	mlx_texture_t	*collect;
// 	xi = 0;
// 	while (game->map.map[xi])
// 	{
// 		yi = 0;
// 		while (game->map.map[xi][yi])
// 		{
// 			if (game->map.map[xi][yi] == 'C')
// 			{
// 				mlx_image_to_window(game->mlx, game->world.collect,
//					game->map.map[xi][yi], game->map.map[xi]);
// 				printf("test\n");
// 			}
// 			yi++;
// 		}
// 		xi++;
// 	}
// }

static void	create_world(t_game *game)
{
	int				xi;
	int				yi;
	mlx_texture_t	*wall;
	mlx_texture_t	*barrel;

	xi = 0;
	wall = mlx_load_png("./textures/Tile.png");
	barrel = mlx_load_png("./textures/Grass.png");
	game->world.wrld = mlx_new_image(game->mlx, game->map.y * 30,
		game->map.x * 30);
	while (game->map.map[xi])
	{
		yi = 0;
		while (game->map.map[xi][yi])
		{
			if (game->map.map[xi][yi] == '1')
				mlx_draw_texture(game->world.wrld, wall, yi * 30, xi * 30);
			if (game->map.map[xi][yi] != '1')
				mlx_draw_texture(game->world.wrld, barrel, yi * 30, xi * 30);
			yi++;
		}
		xi++;
	}
}

void	build_game(t_game	game)
{
	int			xi;
	int			yi;

	game.mlx = mlx_init(game.map.y * 30, game.map.x * 30, "so_long", true);
	if (!game.mlx)
		error(ERR_MLX);
	create_world(&game);
	mlx_image_to_window(game.mlx, game.world.wrld, 0, 0);
	place_player(&game);
	mlx_image_to_window(game.mlx, game.player.img,
		game.map.player[1] * 30, game.map.player[0] * 30);
	mlx_loop_hook(game.mlx, ft_input_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
