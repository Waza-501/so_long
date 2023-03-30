/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_converter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:26 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/30 18:37:04 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static int	compare_line(t_map *map, int size[2], int fd, int i)
{
	map->map[i] = get_next_line(fd);
	if (map->map[i] == NULL)
		return (i + 1);
	size[i % 2] = ft_strlen(map->map[i]);
	if (map->map[i][size[i % 2] - 1] == '\n')
	{
		map->map[i][size[i % 2] - 1] = '\0';
		size[i % 2]--;
	}
	if (size[(i + 1) % 2] != size[i % 2] && i != 0)
		error(ERR_MP_RECT);
	map->y = size [i % 2];
	return (i + 1);
}

/*function pull the map from the file and move it into the map struct*/

void	open_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	int		size[2];
	int		xi;
	int		yi;

	xi = 0;
	yi = 0;
	i = 0;
	size[1] = 0;
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
	// while (map->map[xi])
	// {
	// 	while (map->map[xi][yi])
	// 	{
	// 		ft_printf("%c", map->map[xi][yi]);
	// 		yi++;
	// 	}
	// 	write(1, "\n", 1);
	// 	yi = 0;
	// 	xi++;
	// }
	close(fd);
}
