/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_solver.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 15:44:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/11 17:27:16 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static void	copy_map(t_map *dst, t_map *src)
{
	int		xi;
	int		yi;

	xi = 0;
	yi = 0;
	dst->x = src->x;
	dst->y = src->y;
	dst->player[0] = src->player[0];
	dst->player[1] = src->player[1];
	dst->map = ft_calloc2(sizeof(char *), src->x + 1);
	if (!dst->map)
		error(ERR_MM);
	while (src->map[xi])
	{
		dst->map[xi] = ft_calloc2(sizeof(char), src->y + 1);
		if (!dst->map[xi])
			error(ERR_MM);
		while (src->map[xi][yi])
		{
			dst->map[xi][yi] = src->map[xi][yi];
			yi++;
		}
		yi = 0;
		xi++;
	}
}

static void	solve_map(t_map *map, t_data *tempdata, int xi, int yi)
{
	if (map->map[xi][yi] == 'C')
		tempdata->track_c++;
	if (map->map[xi][yi] == 'E')
		tempdata->track_e++;
	map->map[xi][yi] = 'X';
	if (map->map[xi + 1][yi] != 'X' && map->map[xi + 1][yi] != '1')
		solve_map(map, tempdata, xi + 1, yi);
	if (map->map[xi - 1][yi] != 'X' && map->map[xi - 1][yi] != '1')
		solve_map(map, tempdata, xi - 1, yi);
	if (map->map[xi][yi + 1] != 'X' && map->map[xi][yi + 1] != '1')
		solve_map(map, tempdata, xi, yi + 1);
	if (map->map[xi][yi - 1] != 'X' && map->map[xi][yi - 1] != '1')
		solve_map(map, tempdata, xi, yi - 1);
}

void	check_solvable(t_map *map, t_data *data)
{
	t_map	tempmap;
	t_data	tempdata;
	int		xi;

	tempdata.track_e = 0;
	tempdata.track_c = 0;
	xi = 0;
	copy_map(&tempmap, map);
	solve_map(&tempmap, &tempdata, tempmap.player[0], tempmap.player[1]);
	if (tempdata.track_c != data->track_c || tempdata.track_e != data->track_e)
		error(ERR_MP_UNSOLV);
	while (tempmap.map[xi])
	{
		free (tempmap.map[xi]);
		xi++;
	}
	free (tempmap.map[xi]);
	free (tempmap.map);
}
