/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:33:56 by owen          #+#    #+#                 */
/*   Updated: 2025/03/27 19:25:14 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

t_player_data	*init_p_data(t_game *game, int i_y, int i_x)
{
	t_player_data	*ret;

	ret = (t_player_data *)malloc(sizeof(t_player_data));
	if (!ret)
		exit_error(MEM_ERROR, game);
	ret->collectibles = 0;
	ret->player_x = i_x;
	ret->player_y = i_y;
	ret->player = NULL;
	return (ret);
}

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

t_textures	*init_textures(t_game *game)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		exit_error(MEM_ERROR, game);
	textures->wall = mlx_load_png("./textures/wall.png");
	if (!textures->wall)
		exit_error(MLX_LOAD_FAIL, game);
	textures->floor = mlx_load_png("./textures/floor.png");
	if (!textures->floor)
		exit_error(MLX_LOAD_FAIL, game);
	textures->collec = mlx_load_png("./textures/flower.png");
	if (!textures->collec)
		exit_error(MLX_LOAD_FAIL, game);
	textures->exit = mlx_load_png("./textures/Kaede.png");
	if (!textures->exit)
		exit_error(MLX_LOAD_FAIL, game);
	textures->pmodel = mlx_load_png("./textures/Shuichi.png");
	if (!textures->pmodel)
		exit_error(MLX_LOAD_FAIL, game);
	textures->world = NULL;
	return (textures);
}

t_game	init_structs(void)
{
	t_game	game;

	game.mlx = NULL;
	game.player = NULL;
	game.map = init_map();
	game.tex = NULL;
	game.collectable = NULL;
	game.counter = NULL;
	game.endgame = false;
	game.moves = 0;
	game.width = 0;
	game.height = 0;
	return (game);
}
