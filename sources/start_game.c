/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 13:09:01 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/26 17:02:56 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"
#include <stdbool.h>

void	set_background(t_game *game)
{
	int			i_y;
	int			i_x;
	mlx_image_t	*walls;
	mlx_image_t	*floor;

	i_y = 0;
	walls = mlx_texture_to_image(game->mlx, game->tex.wall);
	floor = mlx_texture_to_image(game->mlx, game->tex.floor);
	if (!walls || !floor)
		exit_error(MLX_LOAD_FAIL, game);
	game->tex.world = mlx_new_image(game->mlx, game->map.max_x * 64,
			game->map.max_y * 64);
	while (game->map.map[i_y])
	{
		i_x = 0;
		while (game->map.map[i_y][i_x])
		{
			if (game->map.map[i_y][i_x] == '1')
				mlx_image_to_window(game->mlx, walls, i_x * 64, i_y * 64);
			else
				mlx_image_to_window(game->mlx, floor, i_x * 64, i_y * 64);
			i_x++;
		}
		i_y++;
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(game->map.max_x * 64, game->map.max_y * 64, "so_long",
			true);
	if (!game->mlx)
		exit_error(MLX_FAILED, game);
	set_background(game);
	mlx_key_hook(game->mlx, &ft_hooky, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
