/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:26 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/13 10:02:14 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	file_check(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4 || ft_strncmp(file[i - 4], ".ber", 4))
		return (-1);
	return (0);
}

int	wall_check()
