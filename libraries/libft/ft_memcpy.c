/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 14:25:56 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/26 23:28:00 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destcpy;
	char	*srccpy;
	size_t	new;

	destcpy = (char *)dest;
	srccpy = (char *)src;
	new = 0;
	if (destcpy == NULL || srccpy == NULL)
		return (srccpy);
	//printf("src is %zu the size is %zu\n", ft_strlen(srccpy), n);
	while (new < n)
	{
		destcpy[new] = srccpy[new];
		new++;
	}
	return (destcpy);
}
