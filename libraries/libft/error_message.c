/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 16:20:15 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/02 13:58:40 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	error_message(char *string)
{
	write (2, string, (ft_strlen(string)));
	write (2, "\n", 2);
}
