/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:14:33 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:12:31 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memset libc function is used to set a number of bytes (count) in
a block of memory (*pointer) to a specific value (value).
*/
#include "../../includes/libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;
	char	*pointer_c;

	i = -1;
	pointer_c = (char *)pointer;
	while (++i < count)
		pointer_c[i] = (char)value;
	return (pointer);
}
