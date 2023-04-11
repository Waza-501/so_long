/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:20:02 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/11 10:18:30 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x - 1;
	y = game->player.y;
	if (game->map.map[x][y] == '1')
		game->mvmnt = 0;
	else
		detect_collision(game, x, y);
	if (game->mvmnt == 1)
	{
		game->player.x = x;
		game->player.y = y;
		game->player.img->instances[0].y -= 30;
		game->counter += 1;
		ft_printf("You have moved a total of %i times.\n", game->counter);
		if (game->allow_leave == 1)
			mlx_close_window(game->mlx);
	}
	game->mvmnt = 1;
}

static void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y - 1;
	if (game->map.map[x][y] == '1')
		game->mvmnt = 0;
	else
		detect_collision(game, x, y);
	if (game->mvmnt == 1)
	{
		game->player.x = x;
		game->player.y = y;
		game->player.img->instances[0].x -= 30;
		game->counter += 1;
		ft_printf("You have moved a total of %i times.\n", game->counter);
		if (game->allow_leave == 1)
			mlx_close_window(game->mlx);
	}
	game->mvmnt = 1;
}

static void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x + 1;
	y = game->player.y;
	if (game->map.map[x][y] == '1')
		game->mvmnt = 0;
	else
		detect_collision(game, x, y);
	if (game->mvmnt == 1)
	{
		game->player.x = x;
		game->player.y = y;
		game->player.img->instances[0].y += 30;
		game->counter += 1;
		ft_printf("You have moved a total of %i times.\n", game->counter);
		if (game->allow_leave == 1)
			mlx_close_window(game->mlx);
	}
	game->mvmnt = 1;
}

static void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y + 1;
	if (game->map.map[x][y] == '1')
		game->mvmnt = 0;
	else
		detect_collision(game, x, y);
	if (game->mvmnt == 1)
	{
		game->player.x = x;
		game->player.y = y;
		game->player.img->instances[0].x += 30;
		game->counter += 1;
		ft_printf("You have moved a total of %i times.\n", game->counter);
		if (game->allow_leave == 1)
			mlx_close_window(game->mlx);
	}
	game->mvmnt = 1;
}

void	ft_keyhook(mlx_key_data_t keydata, void *input)
{
	t_game	*newgame;

	newgame = input;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(newgame->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(newgame);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(newgame);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(newgame);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(newgame);
}
