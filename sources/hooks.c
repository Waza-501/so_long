/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 15:24:41 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/25 17:34:03 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hooky(mlx_key_data_t key, void *input)
{
	t_game	*copy;

	copy = input;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(copy->mlx);
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
	{
		mlx_delete_image(copy->mlx, copy->counter);
		copy->counter = mlx_put_string(copy->mlx, "this is a problem :O", 0, 0);
	}
	if (key.key == MLX_KEY_A && key.action == MLX_RELEASE)
	{
		mlx_delete_image(copy->mlx, copy->counter);
		copy->counter = mlx_put_string(copy->mlx, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa :D", 0, 0);
	}
}
