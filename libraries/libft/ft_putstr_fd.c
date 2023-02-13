/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 14:22:00 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:35:58 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	if (s)
		write(fd, s, ft_strlen(s));
}
