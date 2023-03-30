/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 13:16:58 by Owen          #+#    #+#                 */
/*   Updated: 2023/03/30 19:07:49 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

static void	place_player(t_world *world, t_player *player)
{
	mlx_texture_t	*character;
	character = mlx_load_png("./textures/Barrel.png");
	player->img = mlx_texture_to_image(world->mlx, character);
	player->x = &player->img->instances->x;
	player->y = &player->img->instances->y;
}

static void	create_world(t_world *world, t_map *map)
{
	int				xi;
	int				yi;
	mlx_texture_t	*wall;

	xi = 0;
	wall = mlx_load_png("./textures/Tile.png");
	world->walls = mlx_new_image(world->mlx, map->x * 20, map->y * 20);
	while (map->map[xi])
	{
		yi = 0;
		while (map->map[xi][yi])
		{
			if (map->map[xi][yi] == '1')
				mlx_draw_texture(world->walls, wall, xi * 20, yi * 20);
			yi++;
		}
		xi++;
	}
}

void	testcase(t_map	*map)
{
	t_world		world;
	t_player	player;
	int			xi;
	int			yi;

	while (map->map[xi])
	{
		yi = 0;
		while (map->map[xi][yi])
		{
			ft_printf("%c", map->map[xi][yi]);
			yi++;
		}
		write(1, "\n", 1);
		xi++;
	}
	world.mlx = mlx_init(map->y * 20, map->x * 20, "so_long", true);
	if (!world.mlx)
		error(ERR_MLX);
	create_world(&world, map);
	mlx_image_to_window(world.mlx, world.walls, 0, 0);
	place_player(&world, &player);
	mlx_image_to_window(world.mlx, player.img, map->player[0] * 20, map->player[1] * 20);
	mlx_loop_hook(world.mlx, ft_hook, world.mlx);
	mlx_loop(world.mlx);
	mlx_terminate(world.mlx);
}
