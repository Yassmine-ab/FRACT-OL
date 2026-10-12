/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:12:56 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:12:08 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memcmp libc function is used to compare the first bytes (size) of
two blocks of memory (*s1 and *s2).
*/
#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = -1;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (++i < size)
	{
		if (s1_c[i] != s2_c[i])
			return ((int)(s1_c[i] - s2_c[i]));
	}
	return (0);
}
/*
casting sn + i to unsigned char to avoid sign extension

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("memcmp: %d\n", memcmp("Hello guys", "Hello fuys", 7));
	printf("ft_memcmp: %d\n", ft_memcmp("Hello guys", "Hello fuys", 7));
	return (0);
}
*/
