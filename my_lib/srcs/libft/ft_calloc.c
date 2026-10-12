/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:34:38 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:11:11 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The calloc libc function is used to allocate a number of bytes (count * size)
dynamically and initialize it to zero.
*/
#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("calloc: %p\n", calloc(5, 5));
	printf("ft_calloc: %p\n", ft_calloc(5, 5));
	return (0);
}
*/
