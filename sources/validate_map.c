/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:33:33 by owen          #+#    #+#                 */
/*   Updated: 2025/03/20 16:40:06 by owhearn       ########   odam.nl         */
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
		if ((ft_strlen(map->map[i_y]) - 1)!= map->max_x)
			exit_error(MAP_RECT);
		i_y++;
	}
}

int	id_tile(t_map *map, char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		return (FAILURE);
	else if (c == 'C')
		map->token_c++;
	else if (c == 'P')
		map->token_p++;
	else if (c == 'E')
	{
		map->token_e++;
	}
	return (SUCCESS);
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
			if (id_tile(map, map->map[i_y][i_x]))
				exit_error(MAP_CHAR);
			i_x++;
		}
		i_y++;
	}
	if (map->token_c)
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
	check_
}
