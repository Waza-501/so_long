/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 19:44:28 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/11 11:10:51 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

void	detect_collision(t_game *game, int x, int y)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./textures/GrassPattern.png");
	if ((game->map.map[x][y]) == 'C')
	{
		game->collected += 1;
		game->map.map[x][y] = '0';
		//mlx_delete_texture(game->world.wrld);
		mlx_draw_texture(game->world.wrld, grass, y * 30, x * 30);
	}
	if ((game->map.map[x][y]) == 'E' &&
		game->collected == game->map.collectibles)
		game->allow_leave = 1;
}
