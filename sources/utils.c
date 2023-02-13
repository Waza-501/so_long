/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:13:11 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/10 17:34:24 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/error_messages.h"
#include <errno.h>

void	error(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putendl_fd(err_msg, 2);
	else
		perror(errno);
}
