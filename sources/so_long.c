/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:23 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/28 12:29:34 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <errno.h>

int	main(int argc, char **argv)
{
	t_data		data;

	errno = 0;
	if (argc != 2)
		error(ERR_INPUT);
	else if (file_check(argv[1]))
		error(ERR_FT);
	open_map(argv[1], &data);
	return (0);
}
