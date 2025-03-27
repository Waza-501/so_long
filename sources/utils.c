/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 18:05:54 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/27 19:25:25 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	detect_col(t_game *game, int i_y, int i_x)
{
	if (game->map.map[i_y][i_x] == 'C')
	{
		game->player->collectibles++;
		game->map.map[i_y][i_x] = '0';
		game->collectable->instances[0].enabled = false;
	}
	if (game->player->collectibles == game->map.token_c)
		game->endgame = true;
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
