/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 12:47:11 by owen          #+#    #+#                 */
/*   Updated: 2025/03/26 23:04:27 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_realloc(void *src, size_t type, size_t size)
{
	char	*copy;

	copy = NULL;
	copy = ft_calloc(type, size);
	if (!copy)
		return (NULL);
	printf("realloc\n");
	ft_memcpy(copy, src, type * size);
	free(src);
	return (copy);
}
