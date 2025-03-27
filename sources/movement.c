/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 14:33:12 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/27 19:38:19 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_move_up(t_game *game, int y, int x)
{
	if (game->map.map[y - 1][x] == '1')
	{
		ft_putendl_fd(COLL_WALL, 1);
		return ;
	}
	detect_col(game, y - 1, x);
	game->player->player_y -= 1;
	game->player->player->instances[0].y -= 64;
	game->moves += 1;
	update_counter(game);
	if (game->map.map[y - 1][x] == 'E' && game->endgame == true)
		mlx_close_window(game->mlx);
}

void	sl_move_left(t_game *game, int y, int x)
{
	if (game->map.map[y][x - 1] == '1')
	{
		ft_putendl_fd(COLL_WALL, 1);
		return ;
	}
	detect_col(game, y, x - 1);
	game->player->player_x -= 1;
	game->player->player->instances[0].x -= 64;
	game->moves += 1;
	update_counter(game);
	if (game->map.map[y][x - 1] == 'E' && game->endgame == true)
		mlx_close_window(game->mlx);
}

void	sl_move_down(t_game *game, int y, int x)
{
	if (game->map.map[y + 1][x] == '1')
	{
		ft_putendl_fd(COLL_WALL, 1);
		return ;
	}
	detect_col(game, y + 1, x);
	game->player->player_y += 1;
	game->player->player->instances[0].y += 64;
	game->moves += 1;
	update_counter(game);
	if (game->map.map[y + 1][x] == 'E' && game->endgame == true)
		mlx_close_window(game->mlx);
}

void	sl_move_right(t_game *game, int y, int x)
{
	if (game->map.map[y][x + 1] == '1')
	{
		ft_putendl_fd(COLL_WALL, 1);
		return ;
	}
	detect_col(game, y, x + 1);
	game->player->player_x += 1;
	game->player->player->instances[0].x += 64;
	game->moves += 1;
	update_counter(game);
	if (game->map.map[y][x + 1] == 'E' && game->endgame == true)
		mlx_close_window(game->mlx);
}
