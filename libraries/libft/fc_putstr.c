/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fc_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 17:09:05 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:31:33 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

int	fc_putstr(char *str)
{
	int	size;

	size = 0;
	if (str)
		size += write(1, str, ft_strlen(str));
	return (size);
}
