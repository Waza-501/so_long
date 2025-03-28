/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 17:41:30 by owen          #+#    #+#                 */
/*   Updated: 2025/03/28 17:42:23 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

void	copy_map(t_map *map, t_map *copy, t_game *game)
{
	int	i_y;

	i_y = 0;
	copy->map = ft_calloc(sizeof(char *), map->max_y + 1);
	if (!copy->map)
		exit_error(MEM_ERROR, game);
	while (map->map[i_y])
	{
		copy->map[i_y] = ft_strdup(map->map[i_y]);
		if (!copy->map[i_y])
			exit_error(MEM_ERROR, game);
		i_y++;
	}
}

void	fill_map(t_game *game, int i_y, int i_x, int sop)
{
	t_map	*map;

	map = &game->copy;
	if (sop >= 10000)
		exit_error(SOP, game);
	if (map->map[i_y][i_x] == 'C')
		map->token_c++;
	if (map->map[i_y][i_x] == 'E')
		map->token_e++;
	map->map[i_y][i_x] = 'X';
	if (map->map[i_y + 1][i_x] != 'X' && map->map[i_y + 1][i_x] != '1')
		fill_map(game, i_y + 1, i_x, sop + 1);
	if (map->map[i_y - 1][i_x] != 'X' && map->map[i_y - 1][i_x] != '1')
		fill_map(game, i_y - 1, i_x, sop + 1);
	if (map->map[i_y][i_x + 1] != 'X' && map->map[i_y][i_x + 1] != '1')
		fill_map(game, i_y, i_x + 1, sop + 1);
	if (map->map[i_y][i_x - 1] != 'X' && map->map[i_y][i_x - 1] != '1')
		fill_map(game, i_y, i_x - 1, sop + 1);
}

void	solve_map(t_map *map, t_game *game)
{
	copy_map(map, &game->copy, game);
	fill_map(game, map->p_spawn[0], map->p_spawn[1], 0);
	if (game->copy.token_c != map->token_c || \
			game->copy.token_e != map->token_e)
		exit_error(MAP_UNSOLVABLE, game);
	free_map(&game->copy);
}
