/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fc_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 14:08:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:31:17 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

int	fc_print_str(char *string)
{
	int		size;

	size = 0;
	if (!string)
	{
		size += write(1, "(null)", 6);
		return (size);
	}
	size += fc_putstr(string);
	return (size);
}
