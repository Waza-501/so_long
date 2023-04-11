/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:28:39 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/11 11:12:07 by ohearn        ########   odam.nl         */
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

	character = mlx_load_png("./textures/Char.png");
	game->player.img = mlx_texture_to_image(game->mlx, character);
}

static void	create_special(t_game *game)
{
	int				xi;
	int				yi;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;

	xi = 0;
	collect = mlx_load_png("./textures/Collect.png");
	exit = mlx_load_png("./textures/Exit.png");
	while (game->map.map[xi])
	{
		yi = 0;
		while (game->map.map[xi][yi])
		{
			if (game->map.map[xi][yi] == 'C')
				mlx_draw_texture(game->world.wrld, collect, yi * 30, xi * 30);
			if (game->map.map[xi][yi] == 'E')
				mlx_draw_texture(game->world.wrld, exit, yi * 30, xi * 30);
			yi++;
		}
		xi++;
	}
}

static void	create_world(t_game *game)
{
	int				xi;
	int				yi;
	mlx_texture_t	*wall;
	mlx_texture_t	*grass;

	xi = 0;
	wall = mlx_load_png("./textures/Water.png");
	grass = mlx_load_png("./textures/GrassPattern.png");
	game->world.wrld = mlx_new_image(game->mlx, game->map.y * 30,
			game->map.x * 30);
	while (game->map.map[xi])
	{
		yi = 0;
		while (game->map.map[xi][yi])
		{
			if (game->map.map[xi][yi] == '1')
				mlx_draw_texture(game->world.wrld, wall, yi * 30, xi * 30);
			if (game->map.map[xi][yi] == '0' || game->map.map[xi][yi] == 'P')
				mlx_draw_texture(game->world.wrld, grass, yi * 30, xi * 30);
			yi++;
		}
		xi++;
	}
	create_special(game);
}

void	build_game(t_game	game)
{
	game.mlx = mlx_init(game.map.y * 30, game.map.x * 30, "so_long", true);
	if (!game.mlx)
		error(ERR_MLX);
	create_world(&game);
	mlx_image_to_window(game.mlx, game.world.wrld, 0, 0);
	place_player(&game);
	mlx_image_to_window(game.mlx, game.player.img,
		game.map.player[1] * 30, game.map.player[0] * 30);
	mlx_key_hook(game.mlx, &ft_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	system("leaks -q so_long");
}
