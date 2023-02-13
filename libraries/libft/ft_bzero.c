/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 17:19:51 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:31:42 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			tally;
	unsigned char	*copy_s;

	tally = 0;
	copy_s = (unsigned char *)s;
	while (tally < n)
	{
		copy_s[tally] = 0;
		++tally;
	}
}
