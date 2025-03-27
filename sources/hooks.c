/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 15:24:41 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/27 17:52:32 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hooky(mlx_key_data_t key, void *input)
{
	t_game	*copy;

	copy = input;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(copy->mlx);
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		sl_move_up(copy, copy->player->player_y, copy->player->player_x);
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		sl_move_left(copy, copy->player->player_y, copy->player->player_x);
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		sl_move_down(copy, copy->player->player_y, copy->player->player_x);
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		sl_move_right(copy, copy->player->player_y, copy->player->player_x);
}
