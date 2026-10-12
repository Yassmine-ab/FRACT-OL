/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:17:53 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:11:39 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_lstclear function deletes and frees a given node of
a linked list and every successor of that node,
using the function (*del) and free.
*lst is the pointer to the node to free and *del is the function
used to delete the node's *content.
Finally, the pointer to the list must be set to NULL.
*/
#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	current = *lst;
	while (*lst && lst)
	{
		*lst = current->next;
		ft_lstdelone(current, del);
		current = *lst;
	}
}
