/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 13:09:01 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/26 10:59:30 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"
#include <stdbool.h>

void	set_background(t_game *game)
{
	int			i_y;
	mlx_image_t	*img;
	//int		i_x;

	(void)i_y;
	game->tex.world = mlx_new_image(game->mlx, game->map.max_x * 64,
			game->map.max_y * 64);
	img = mlx_texture_to_image(game->mlx, game->tex.wall);
	mlx_image_to_window(game->mlx, img, 0, 0);
	mlx_image_to_window(game->mlx, img, 0, 64);
	mlx_image_to_window(game->mlx, img, 0, 128);
	mlx_image_to_window(game->mlx, img, 0, 196);
	mlx_image_to_window(game->mlx, img, 64, 0);
	mlx_image_to_window(game->mlx, img, 128, 0);
	mlx_image_to_window(game->mlx, img, 196, 0);
	mlx_image_to_window(game->mlx, img, 256, 0);
	game->counter = mlx_put_string(game->mlx, "testing :D", 0, 0);
}

void	start_game(t_game *game)
{
	printf("dimensions are %zu %zu\n", game->map.max_y, game->map.max_x);
	game->mlx = mlx_init(game->map.max_x * 64, game->map.max_y * 64, "so_long",
			true);
	if (!game->mlx)
		exit_error(MLX_FAILED);
	set_background(game);
	mlx_key_hook(game->mlx, &ft_hooky, game);
	mlx_loop(game->mlx);
	free_textures(game);
	mlx_terminate(game->mlx);
}
