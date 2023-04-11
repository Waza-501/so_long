/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 15:19:47 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/11 11:57:49 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

t_map	init_map(void)
{
	t_map	to_return;

	to_return.collectibles = 0;
	to_return.exit[0] = 0;
	to_return.exit[1] = 0;
	to_return.map = NULL;
	to_return.player[0] = 0;
	to_return.player[1] = 0;
	to_return.x = 0;
	to_return.y = 0;
	return (to_return);
}

t_world	init_world(void)
{
	t_world		wrld;

	wrld.mlx = NULL;
	wrld.wrld = NULL;
	wrld.water = mlx_load_png("./textures/Water.png");
	wrld.grass = mlx_load_png("./textures/GrassPattern.png");
	wrld.collectible = mlx_load_png("./textures/Collect.png");
	wrld.exit = mlx_load_png("./textures/Exit.png");
	return (wrld);
}

t_player	init_player(void)
{
	t_player	newplyr;

	newplyr.x = 0;
	newplyr.y = 0;
	newplyr.img = NULL;
	newplyr.pmodel = mlx_load_png("./textures/Char.png");
	return (newplyr);
}

t_game	init_game(void)
{
	t_game	newgame;

	newgame.wi = 0;
	newgame.he = 0;
	newgame.mlx = NULL;
	newgame.collected = 0;
	newgame.mvmnt = 1;
	newgame.counter = 0;
	newgame.allow_leave = 0;
	newgame.map = init_map();
	newgame.world = init_world();
	newgame.player = init_player();
	return (newgame);
}
