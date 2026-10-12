/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:19:49 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:12:00 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_lstsize function counts the number of nodes in a linked list.
*lst is the pointer to the first node of the list and
*size is the length of the linked list.
*/
#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	if (!lst)
		return (0);
	size = -1;
	while (++size >= 0 && lst)
		lst = lst->next;
	return (size);
}
