/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 12:17:22 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/19 12:17:46 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char	*error_code)
{
	ft_putendl_fd("ERROR", 2);
	if (errno == 0)
		ft_putendl_fd(error_code, 2);
	else
		perror(error_code);
	exit(-1);
}
