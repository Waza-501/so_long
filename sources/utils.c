/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 18:05:54 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/25 18:38:22 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_counter(t_game *game)
{
	char	*str;

	str = ft_strjoin("Total moves: ", ft_itoa(game->moves));
	if (!str)
		write (2, "Error updating move counter.\n", 29);
	mlx_delete_image(game->mlx, game->counter);
	game->counter = mlx_put_string(game->mlx, str, 0, 0);
}
