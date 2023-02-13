/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:23 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/12 11:13:44 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/error_messages.h"
#include <errno.h>

int	main(int argc, char **argv)
{
	errno = 0;
	if (argc != 2)
		error(ERR_INPUT);
	else if (file_check(argv[1]))
		error(ERR_FT);
	return (0);
}
