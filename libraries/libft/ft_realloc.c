/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 12:47:11 by owen          #+#    #+#                 */
/*   Updated: 2025/03/12 16:39:57 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t type, size_t size)
{
	char	*copy;

	copy = ft_calloc(type, size);
	if (!copy)
		return (copy);
	ft_memcpy(copy, src, size);
	free(src);
	return (copy);
}
