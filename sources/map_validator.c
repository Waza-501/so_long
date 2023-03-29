/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validator.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:21:50 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/29 16:00:01 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

void	count_char(t_map *map, t_data *data, int xi, int yi)
{
	if (map->map[xi][yi] == 'P')
	{
		data->track_p++;
		if (data->track_p == 1)
		{
			map->player[0] = xi;
			map->player[1] = yi;
		}
	}
	if (map->map[xi][yi] == 'C')
	{
		data->track_c++;
		map->collectibles++;
	}
	if (map->map[xi][yi] == 'E')
	{
		data->track_e++;
		if (data->track_e == 1)
		{
			map->exit[0] = xi;
			map->exit[1] = yi;
		}
	}
}

int	valid_char(char c)
{
	int		i;
	int		t;
	char	*valid;

	i = 0;
	t = 0;
	valid = "01CEP";
	while (valid[i])
	{
		if (c == valid[i])
			t++;
		i++;
	}
	if (t == 0)
		return (1);
	return (0);
}

static void	check_map(t_map *map, t_data *data)
{
	int		xi;
	int		yi;

	xi = 0;
	yi = 0;
	while (map->map[xi])
	{
		while (map->map[xi][yi])
		{
			if (xi == 0 || yi == 0 || xi == map->x - 1 || yi == map->y - 1)
			{
				if (map->map[xi][yi] != '1')
					error(ERR_MP_WALLS);
			}
			if (valid_char(map->map[xi][yi]) != 0)
				error(ERR_MP_CHAR);
			if (map->map[xi][yi] == 'P' || map->map[xi][yi] == 'C' ||
				map->map == "E" )
			{
				count_char(map->map[xi][yi], xi, yi);
			}
			yi++;
		}
		xi++;
	}
}

static void	requirements_met(t_data *data)
{
	if (data->track_p == 0)
		error(ERR_MP_NOSPWN);
	if (data->track_p > 1)
		error(ERR_MP_SPWN);
	if (data->track_c < 1)
		error(ERR_MP_COL);
	if (data->track_e == 0)
		error(ERR_MP_NOEXIT);
	if (data->track_e < 1)
		error(ERR_MP_EXIT);
}

void	validate_map(t_map *map, t_data *data)
{
	check_map(map, data);
	requirements_met (data);
	check_solvable(map, data);
}

/*To make sure map is solvable, make a copy of the map and go through it one by one, replacing any tile the P touches with an X.
Next loop, and every loop after it, replace any 0, C or E tiles with X.
Create an int to keep track if tiles are changed.
When the int does't get incremented and the correct number of collectibles and the exit haven't been touched, the map isn't solveable.

Thank you Nick for giving me the idea on how to go about it*/