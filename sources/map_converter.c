/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_converter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:26 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/02 13:29:31 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static int	compare_line(t_map *map, int strl, int fd, int i)
{
	map->map[i] = get_next_line(fd);
	if (map->map[i] == NULL)
		return (i + 1);
	strl = ft_strlen(map->map[i]);
	if (map->map[i][strl - 1] == '\n')
	{
		map->map[i][strl - 1] = '\0';
		strl = strl - 1;
	}
	if (map->y != 0 && map->y != strl)
		error(ERR_MP_RECT);
	map->y = strl;
	return (i + 1);
}

/*function pull the map from the file and move it into the map struct*/

void	open_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	int		size;
	int		xi;
	int		yi;

	xi = 0;
	yi = 0;
	i = 0;
	size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(ERR_FD);
	map->map = ft_calloc2(sizeof(char *), i + 1);
	i = compare_line(map, size, fd, i);
	while (map->map[i - 1] != NULL)
	{
		map->map = ft_realloc(map->map, sizeof(char *) * (i + 1));
		i = compare_line(map, size, fd, i);
	}
	map->x = i - 1;
	close(fd);
}
