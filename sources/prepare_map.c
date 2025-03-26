/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 12:19:12 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/26 11:21:05 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"
#include <fcntl.h>

void	pull_map_from_file(t_map *map, int fd)
{
	int		idx;
	size_t	size;

	idx = 0;
	map->map = ft_calloc(sizeof(char *), idx + 1);
	if (!map->map)
		exit_error(MEM_ERROR);
	map->map[idx] = get_next_line(fd);
	while (map->map[idx] != NULL)
	{
		size = ft_strlen(map->map[idx]);
		if (map->map[idx][size - 1] == '\n')
			map->map[idx][size - 1] = '\0';
		//printf("%s\n", map->map[idx]);
		idx++;
		map->map = ft_realloc(map->map, sizeof(char *), idx + 1);
		map->map[idx] = get_next_line(fd);
	}
	map->max_y = idx;
	map->max_x = ft_strlen(map->map[0]);
}

void	prepare_map(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(FD_ERROR);
	pull_map_from_file(map, fd);
	close(fd);
	validate_map(map);
}
