/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:33:33 by owen          #+#    #+#                 */
/*   Updated: 2025/03/19 17:47:00 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

void	check_rectangle(t_map *map)
{
	size_t	i_y;

	i_y = 0;
	while (i_y <= map->max_y)
	{
		if (ft_strlen(map->map[i_y]) != map->max_x)
			exit_error(MAP_RECT);
		i_y++;
	}
}

void	check_valid_tokens(t_map *map)
{
	size_t	i_x;
	size_t	i_y;

	i_y = 0;
	while (i_y <= map->max_y)
	{
		i_x = 0;
		while (i_x <= map->max_x)
		{
			if 
		}
	}
}

/*void	check_borders(t_map *map)
{
	size_t	i_x;
	size_t	i_y;

	i_x = 0;
	i_y = 0;
	while (i_y <= map->max_y)
	{

	}
}*/

void	validate_map(t_map *map)
{
	t_map	*copy;

	copy = map;
	check_rectangle(copy);
	printf("is rectangle :D\n");
	check_valid_tokens(copy);
	printf("is valid :D\n");
	check_borders(copy);
}
