/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:20:02 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/06 18:01:38 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

void	ft_hook(void *param)
{
	mlx_t		*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_input_hook(void *input)
{
	t_game	*newgame;

	newgame = input;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(newgame->mlx);
}
