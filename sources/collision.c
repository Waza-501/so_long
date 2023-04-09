/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 19:44:28 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/09 18:23:28 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

// static int	detect_north(t_game game, int x, int y)
// {
// 	if ((game.map.map[x][y]) == 'C')
// 	{
// 		game.collected++;
// 		game.map.map[x][y] = '0';
// 	}
// 	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
// 	{
// 		mlx_close_window(game.mlx);
// 		mlx_terminate(game.mlx);
// 	}
// 	return (0);
// }

// static int	detect_east(t_game game, int x, int y)
// {
// 	if ((game.map.map[x][y]) == 'C')
// 	{
// 		game.collected++;
// 		game.map.map[x][y] = '0';
// 	}
// 	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
// 	{
// 		mlx_close_window(game.mlx);
// 		mlx_terminate(game.mlx);
// 	}
// 	return (0);
// }

// static int	detect_south(t_game game, int x, int y)
// {
// 	if ((game.map.map[x][y]) == 'C')
// 	{
// 		game.collected++;
// 		game.map.map[x][y] = '0';
// 	}
// 	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
// 	{
// 		mlx_close_window(game.mlx);
// 		mlx_terminate(game.mlx);
// 	}
// 	return (0);
// }

// static int	detect_west(t_game game, int x, int y)
// {
// 	if ((game.map.map[x][y]) == 'C')
// 	{
// 		game.collected++;
// 		game.map.map[x][y] = '0';
// 	}
// 	if ((game.map.map[x][y]) == 'E' && game.collected == game.map.collectibles)
// 	{
// 		mlx_close_window(game.mlx);
// 		mlx_terminate(game.mlx);
// 	}
// 	return (0);
// }

void	detect_collision(t_game *game, int x, int y)
{

	if ((game->map.map[x][y]) == 'C')
	{
		game->collected += 1;
		printf("collectible found! Total collectibles found %i\n", game->collected);
		game->map.map[x][y] = '0';
	}
	if ((game->map.map[x][y]) == 'E' && game->collected == game->map.collectibles)
		game->allow_leave = 1;
}
