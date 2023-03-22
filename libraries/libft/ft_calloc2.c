/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 14:08:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/22 14:13:02 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_calloc2(unsigned long count, unsigned long size)
{
	char	*ret;

	ret = malloc((count * size));
	if (!ret)
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}
