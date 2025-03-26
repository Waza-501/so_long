/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 12:17:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/26 17:02:31 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_game *game)
{
	if (game->tex.wall)
		mlx_delete_texture(game->tex.wall);
	if (game->tex.floor)
		mlx_delete_texture(game->tex.floor);
	if (game->tex.collec)
		mlx_delete_texture(game->tex.collec);
	if (game->tex.exit)
		mlx_delete_texture(game->tex.exit);
	if (game->tex.pmodel)
		mlx_delete_texture(game->tex.pmodel);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_game(t_game *game)
{
	free_textures(game);
	free_map(&game->map);
}

void	exit_error(char	*error_code, t_game *game)
{
	ft_putendl_fd("ERROR", 2);
	if (game)
		free_game(game);
	if (errno == 0)
		ft_putendl_fd(error_code, 2);
	else
		perror(error_code);
	exit(-1);
}
