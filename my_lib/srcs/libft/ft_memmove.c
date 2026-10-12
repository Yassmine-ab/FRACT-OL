/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:14:16 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:12:27 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memmove libc function is safe to use when the source (*src) and
destination (*dest) memory blocks overlap, unlike memcpy.
*/
#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_c;
	char	*src_c;

	dest_c = (char *)dest;
	src_c = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest_c > src_c)
	{
		while (n-- > 0)
			dest_c[n] = src_c[n];
	}
	else
	{
		i = -1;
		while (++i < n)
			dest_c[i] = src_c[i];
	}
	return (dest);
}
