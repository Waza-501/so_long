/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 11:16:02 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:36:58 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		length;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	length = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[length]))
		length--;
	return (ft_substr(s1, 0, length + 1));
}
