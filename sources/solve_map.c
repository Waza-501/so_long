/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 17:41:30 by owen          #+#    #+#                 */
/*   Updated: 2025/03/25 10:49:35 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

void	copy_map(t_map *map, t_map *copy)
{
	int	i_y;
	int	i_x;

	i_y = 0;
	copy->map = ft_calloc(sizeof(char *), copy->max_y);
	if (!copy->map)
		exit_error(MEM_ERROR);
	while (map->map[i_y])
	{
		i_x = 0;
		copy->map[i_y] = ft_calloc(sizeof(char *), copy->max_x);
		if (!copy->map[i_y])
			exit_error(MEM_ERROR);
		//ft_memcpy(copy->map[i_y], map->map[i_y], copy->max_x)
		while (copy->map[i_y][i_x])
		{
			copy->map[i_y][i_x] = map->map[i_y][i_x];
			i_x++;
		}
		i_y++;
	}
	
}

void	fill_map(t_map *map)
{
	
	
}

void	solve_map(t_map *map)
{
	t_map	copy;

	copy = init_map();
	copy.max_y = map->max_y;
	copy.max_x = map->max_x;
	copy.e_spawn[0] = map->e_spawn[0];
	copy.e_spawn[1] = map->e_spawn[1];
	copy.p_spawn[0] = map->p_spawn[0];
	copy.p_spawn[1] = map->p_spawn[1];
	copy_map(map->map, &copy);
	fill_map(&copy);
	free_map(&copy);
}
