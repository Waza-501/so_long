/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 13:16:58 by Owen          #+#    #+#                 */
/*   Updated: 2023/04/06 18:01:44 by ohearn        ########   odam.nl         */
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
	printf("Hello there\n");
	game->player.img = mlx_texture_to_image(game->mlx, character);
	// game->player.x = &game->player.img->instances->x;
	// game->player.y = &game->player.img->instances->y;
}

static void	create_world(t_game *game)
{
	int				xi;
	int				yi;
	mlx_texture_t	*wall;

	xi = 0;
	wall = mlx_load_png("./textures/Tile.png");
	printf("test\n");
	game->world.walls = mlx_new_image(game->mlx, game->map.y * 20, game->map.x * 20);
	while (game->map.map[xi])
	{
		yi = 0;
		while (game->map.map[xi][yi])
		{
			if (game->map.map[xi][yi] == '1')
				mlx_draw_texture(game->world.walls, wall, yi * 20, xi * 20);
			ft_printf("%i xi, %i yi\n", xi, yi);
			ft_printf("%c number\n", game->map.map[xi][yi]);
			yi++;
		}
		xi++;
	}
}

void	testcase(t_game	game)
{
	int			xi;
	int			yi;

	game.mlx = mlx_init(game.map.y * 20, game.map.x * 20, "so_long", true);
	if (!game.mlx)
		error(ERR_MLX);
	create_world(&game);
	mlx_image_to_window(game.mlx, game.world.walls, 0, 0);
	place_player(&game);
	mlx_image_to_window(game.mlx, game.player.img,
		game.map.player[1] * 20, game.map.player[0] * 20);
	printf("Hello there\n");
	mlx_loop_hook(game.mlx, ft_input_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
