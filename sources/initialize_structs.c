/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:33:56 by owen          #+#    #+#                 */
/*   Updated: 2025/03/13 16:59:48 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.map = NULL;
	map.x = 0;
	map.y = 0;
	map.max_x = 0;
	map.max_y = 0;
	return (map);
}

t_game	init_structs(void)
{
	t_game	game;

	game.mlx = NULL;
	game.player = NULL;
	game.map = init_map();
	game.width = 0;
	game.height = 0;
	return (game);
}
