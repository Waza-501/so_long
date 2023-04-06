/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 15:19:47 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/06 18:02:53 by ohearn        ########   odam.nl         */
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
	wrld.walls = NULL;
	return (wrld);
}

t_player	init_player(void)
{
	t_player	newplyr;

	newplyr.x = 0;
	newplyr.y = 0;
	newplyr.img = NULL;
	return (newplyr);
}

t_game	init_game(void)
{
	t_game	newgame;

	newgame.wi = 0;
	newgame.he = 0;
	newgame.mlx = NULL;
	newgame.map = init_map();
	newgame.world = init_world();
	newgame.player = init_player();
	return (newgame);
}
