/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 14:53:47 by owhearn       #+#    #+#                 */
/*   Updated: 2025/03/11 14:16:22 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*combine;

	size = 0;
	combine = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!combine)
		return (NULL);
	while (s1 != NULL && *s1)
	{
		combine[size] = *s1;
		s1++;
		size++;
	}
	while (s2 != NULL && *s2)
	{
		combine[size] = *s2;
		s2++;
		size++;
	}
	combine[size] = '\0';
	return (combine);
}
