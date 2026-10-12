/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:13:49 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:12:13 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memcpy libc function is used to copy a number of bytes (n) from
a source memory block (*src) to a destination memory block (*dest).
*/
#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_c;
	char	*src_c;

	i = -1;
	dest_c = (char *)dest;
	src_c = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (++i < n)
		dest_c[i] = src_c[i];
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("memcpy: %d\n", memcpy("Hello guys", "Hello fuys", 7));
	printf("ft_memcpy : %d\n", ft_memcpy("Hello guys", "Hello fuys", 7));
	return (0);
}
*/
