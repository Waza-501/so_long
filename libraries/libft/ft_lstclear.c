/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 17:36:18 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:33:43 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp;
	t_list		*temp2;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		temp2 = temp;
		del(temp->content);
		temp = temp->next;
		free(temp2);
	}
	*lst = NULL;
}
