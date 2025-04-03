/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 13:09:01 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/03 15:25:25 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"
#include <stdbool.h>

void	set_player(t_game *game)
{
	game->player->player = mlx_texture_to_image(game->mlx, game->tex->pmodel);
	if (!game->player->player)
		exit_error(MLX_LOAD_TTI, game);
	mlx_image_to_window(game->mlx, game->player->player,
		game->map.p_spawn[1] * 30, game->map.p_spawn[0] * 30);
}

void	set_foreground(t_game *game, int i_y, int i_x)
{
	mlx_image_t	*collec;
	mlx_image_t	*exit;

	collec = mlx_texture_to_image(game->mlx, game->tex->collec);
	exit = mlx_texture_to_image(game->mlx, game->tex->exit);
	if (!collec || !exit)
		exit_error(MLX_LOAD_TTI, game);
	mlx_image_to_window(game->mlx, exit, game->map.e_spawn[1] * 30,
		game->map.e_spawn[0] * 30);
	while (game->map.map[i_y])
	{
		i_x = 0;
		while (game->map.map[i_y][i_x])
		{
			if (game->map.map[i_y][i_x] == 'C')
				mlx_image_to_window(game->mlx, collec, i_x * 30, i_y * 30);
			i_x++;
		}
		i_y++;
	}
	game->collectable = collec;
	set_player(game);
}

void	set_background(t_game *game, int i_y, int i_x)
{
	mlx_image_t	*walls;
	mlx_image_t	*floor;

	walls = mlx_texture_to_image(game->mlx, game->tex->wall);
	floor = mlx_texture_to_image(game->mlx, game->tex->floor);
	if (!walls || !floor)
		exit_error(MLX_LOAD_TTI, game);
	game->tex->world = mlx_new_image(game->mlx, game->map.max_x * 30,
			game->map.max_y * 30);
	while (game->map.map[i_y])
	{
		i_x = 0;
		while (game->map.map[i_y][i_x])
		{
			if (game->map.map[i_y][i_x] == '1')
				mlx_image_to_window(game->mlx, walls, i_x * 30, i_y * 30);
			else
				mlx_image_to_window(game->mlx, floor, i_x * 30, i_y * 30);
			i_x++;
		}
		i_y++;
	}
}

void	start_game(t_game *game)
{
	int			i_y;
	int			i_x;

	i_y = 0;
	i_x = 0;
	if (game->map.max_y > 500 || game->map.max_x > 500)
		exit_error(SOP, game);
	game->player = init_p_data(game, game->map.p_spawn[0],
			game->map.p_spawn[1]);
	game->tex = init_textures(game);
	game->mlx = mlx_init(game->map.max_x * 30, game->map.max_y * 30, "so_long",
			true);
	if (!game->mlx)
		exit_error(MLX_FAILED, game);
	set_background(game, i_y, i_x);
	set_foreground(game, i_y, i_x);
	mlx_key_hook(game->mlx, &ft_hooky, game);
	mlx_loop(game->mlx);
}
