/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 17:41:30 by owen          #+#    #+#                 */
/*   Updated: 2025/03/25 12:45:50 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

void	copy_map(t_map *map, t_map *copy)
{
	int	i_y;

	i_y = 0;
	copy->map = ft_calloc(sizeof(char *), map->max_y + 1);
	if (!copy->map)
		exit_error(MEM_ERROR);
	while (map->map[i_y])
	{
		copy->map[i_y] = ft_strdup(map->map[i_y]);
		if (!copy->map[i_y])
			exit_error(MEM_ERROR);
		i_y++;
	}
}

void	fill_map(t_map *map, int i_y, int i_x)
{
	if (map->map[i_y][i_x] == 'C')
		map->token_c++;
	if (map->map[i_y][i_x] == 'E')
		map->token_e++;
	map->map[i_y][i_x] = 'X';
	if (map->map[i_y + 1][i_x] != 'X' && map->map[i_y + 1][i_x] != '1')
		fill_map(map, i_y + 1, i_x);
	if (map->map[i_y - 1][i_x] != 'X' && map->map[i_y - 1][i_x] != '1')
		fill_map(map, i_y - 1, i_x);
	if (map->map[i_y][i_x + 1] != 'X' && map->map[i_y][i_x + 1] != '1')
		fill_map(map, i_y, i_x + 1);
	if (map->map[i_y][i_x - 1] != 'X' && map->map[i_y][i_x - 1] != '1')
		fill_map(map, i_y, i_x - 1);
}

void	solve_map(t_map *map)
{
	t_map	copy;
	int		i;

	copy = init_map();
	copy_map(map, &copy);
	fill_map(&copy, map->p_spawn[0], map->p_spawn[1]);
	i = 0;
	while (copy.map[i])
	{
		printf("%s\n", copy.map[i]);
		i++;
	}
	if (copy.token_c != map->token_c || copy.token_e != map->token_e)
		exit_error(MAP_UNSOLVABLE);
	free_map(&copy);
}
