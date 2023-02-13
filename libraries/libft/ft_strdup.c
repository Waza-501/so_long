/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 16:02:46 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:36:12 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc(ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}
