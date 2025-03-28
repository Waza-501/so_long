/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 18:05:54 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/28 10:28:38 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_instance(t_game *game, int y, int x)
{
	int	ret;
	int	idx;

	ret = -1;
	idx = 0;
	while (game->collectable->instances[idx].y)
	{
		while (game->collectable->instances[idx].y == y)
		{
			if (game->collectable->instances[idx].x == x)
				return (idx);
			idx++;
		}
		idx++;
	}
	return (ret);
}

void	detect_col(t_game *game, int i_y, int i_x)
{
	int	idx;

	if (game->map.map[i_y][i_x] == 'C')
	{
		game->player->collectibles++;
		game->map.map[i_y][i_x] = '0';
		idx = find_instance(game, i_y * 64, i_x * 64);
		if (idx >= 0)
			game->collectable->instances[idx].enabled = false;
	}
	if (game->player->collectibles == game->map.token_c)
	{
		if (game->endgame == false)
			ft_putendl_fd("The exit has opened!!!", 1);
		game->endgame = true;
	}
}

void	update_counter(t_game *game)
{
	char	*str;
	char	*idx;

	idx = ft_itoa(game->moves);
	if (!idx)
	{
		write (2, "Error updating move counter.\n", 29);
		return ;
	}
	str = ft_strjoin("Total moves: ", idx);
	if (!str)
	{
		write (2, "Error updating move counter.\n", 29);
		free(idx);
		return ;
	}
	mlx_delete_image(game->mlx, game->counter);
	game->counter = mlx_put_string(game->mlx, str, 0, 0);
	free(idx);
	free(str);
}
