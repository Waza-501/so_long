/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:33:56 by owen          #+#    #+#                 */
/*   Updated: 2025/03/20 16:42:46 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.map = NULL;
	map.p_spawn[0] = 0;
	map.p_spawn[1] = 0;
	map.e_spawn[0] = 0;
	map.e_spawn[1] = 0;
	map.max_x = 0;
	map.max_y = 0;
	map.token_c = 0;
	map.token_e = 0;
	map.token_p = 0;
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
