/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:33:33 by owen          #+#    #+#                 */
/*   Updated: 2025/03/25 16:23:46 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

void	check_rectangle(t_map *map)
{
	size_t	i_y;

	i_y = 0;
	while (i_y < map->max_y)
	{
		if ((ft_strlen(map->map[i_y])) != map->max_x)
			exit_error(MAP_RECT);
		i_y++;
	}
}

int	id_tile(t_map *map, char c, int i_y, int i_x)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		return (FAILURE);
	else if (c == 'C')
		map->token_c++;
	else if (c == 'P')
	{
		map->token_p++;
		map->p_spawn[0] = i_y;
		map->p_spawn[1] = i_x;
	}
	else if (c == 'E')
	{
		map->token_e++;
		map->e_spawn[0] = i_y;
		map->e_spawn[1] = i_x;
	}
	return (SUCCESS);
}

void	check_valid_tokens(t_map *map)
{
	size_t	i_x;
	size_t	i_y;

	i_y = 0;
	while (i_y < map->max_y)
	{
		i_x = 0;
		while (i_x < map->max_x)
		{
			if (id_tile(map, map->map[i_y][i_x], i_y, i_x))
				exit_error(MAP_CHAR);
			if (i_y == 0 || i_x == 0 || i_y == map->max_y - 1
				|| i_x == map->max_x - 1)
				if (map->map[i_y][i_x] != '1')
					exit_error(MAP_WALLS);
			i_x++;
		}
		i_y++;
	}
	if (map->token_c < 1)
		exit_error(MAP_COL);
	if (map->token_e != 1)
		exit_error(MAP_EXIT);
	if (map->token_p != 1)
		exit_error(MAP_SPAWN);
}

void	validate_map(t_map *map)
{
	t_map	*copy;

	copy = map;
	check_rectangle(copy);
	check_valid_tokens(copy);
	solve_map(copy);
}
