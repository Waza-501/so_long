/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 14:04:32 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:35:44 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
