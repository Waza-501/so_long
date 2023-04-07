/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:20:02 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/07 15:47:35 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

void	ft_input_hook(void *input)
{
	t_game	*newgame;

	newgame = input;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(newgame->mlx);
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_UP))
		newgame->player.img->instances[0].y -= 2;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_DOWN))
		newgame->player.img->instances[0].y += 2;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_LEFT))
		newgame->player.img->instances[0].x -= 1;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_RIGHT))
		newgame->player.img->instances[0].x += 1;
}
