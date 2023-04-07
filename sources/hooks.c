/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:20:02 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/07 20:16:50 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static void	move_up(t_game game)
{
	int	x;
	int	y;

	x = game.player.x + 1;
	y = game.player.y;
	if (game.map.map[x][y] == '1')
		return ;
	else
		detect_collision(game, x, y);
	game.player.img->instances[0].x += 5;
}

static void	move_left(t_game game)
{

}
static void	move_down(t_game game)
{

}

static void	move_right(t_game game)
{

}

void	ft_input_hook(void *input)
{
	t_game	*newgame;

	newgame = input;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(newgame->mlx);
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_UP))
		move_up(*newgame);
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_DOWN))
		newgame->player.img->instances[0].y += 5;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_LEFT))
		newgame->player.img->instances[0].x -= 5;
	if (mlx_is_key_down(newgame->mlx, MLX_KEY_RIGHT))
		newgame->player.img->instances[0].x += 5;
}
