/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 19:44:28 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/07 22:55:29 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static int	detect_north(t_game game, int x, int y)
{
	if ((game.map.map[x][y]) == 'C')
	{
		game.collected++;
		game.map.map[x][y] = '0';
	}
	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
	{
		mlx_close_window(game.mlx);
		mlx_terminate(game.mlx);
	}
	return (0);
}

static int	detect_east(t_game game, int x, int y)
{
	if ((game.map.map[x][y]) == 'C')
	{
		game.collected++;
		game.map.map[x][y] = '0';
	}
	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
	{
		mlx_close_window(game.mlx);
		mlx_terminate(game.mlx);
	}
	return (0);
}

static int	detect_south(t_game game, int x, int y)
{
	if ((game.map.map[x][y]) == 'C')
	{
		game.collected++;
		game.map.map[x][y] = '0';
	}
	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
	{
		mlx_close_window(game.mlx);
		mlx_terminate(game.mlx);
	}
	return (0);
}

static int	detect_west(t_game game, int x, int y)
{
	if ((game.map.map[x][y]) == 'C')
	{
		game.collected++;
		game.map.map[x][y] = '0';
	}
	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
	{
		mlx_close_window(game.mlx);
		mlx_terminate(game.mlx);
	}
	return (0);
}

void	detect_collision(t_game game, int x, int y)
{
	if (detect_north(game, x, y) == 1 || detect_east(game, x, y) == 1
		|| detect_south(game, x, y) == 1 || detect_west(game, x, y) == 1)
		return ;
	return ;
}
