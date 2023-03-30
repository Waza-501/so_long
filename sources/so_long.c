/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:23 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/30 16:17:44 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	tracker_reset(t_data *data)
{
	data->track_c = 0;
	data->track_e = 0;
	data->track_p = 0;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_game		game;
	int			temp;

	errno = 0;
	if (argc != 2)
		error(ERR_INPUT);
	else if (file_check(argv[1]))
		error(ERR_FT);
	open_map(argv[1], &map);
	tracker_reset(&data);
	validate_map(&map, &data);
	write(1, "Everything checks out so far\n", 29);
	testcase(&map);
	return (0);
}
