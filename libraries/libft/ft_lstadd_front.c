/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 17:46:50 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:33:28 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (!lst || !new || !*lst)
		return ;
	new->next = *lst;
	*lst = new;
}
