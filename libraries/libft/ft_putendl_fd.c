/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 14:37:06 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:35:48 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}
