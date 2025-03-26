/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 12:47:11 by owen          #+#    #+#                 */
/*   Updated: 2025/03/26 17:25:45 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t type, size_t size)
{
	char	*copy;

	copy = NULL;
	copy = ft_calloc(type, size);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, src, type * size);
	free(src);
	return (copy);
}
