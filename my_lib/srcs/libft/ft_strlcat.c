/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:15:26 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:42:59 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlcat libc function is used to concatenate two strings (*dest and *src)
into a new string (*dest) with a specified size (size)
*/
#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = -1;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if ((!dest || !src) && !size)
		return (0);
	if (size < dest_len + 1)
		return (size + src_len);
	if (size > dest_len + 1)
	{
		while (src[++i] && (dest_len + i) < (size - 1))
			dest[dest_len + i] = src[i];
	}
	else
		i++;
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>

int main(void)
{
	char dest[20] = "Hello, ";
	const char *src = "world!";
	size_t size = sizeof(dest);
	size_t result = ft_strlcat(dest, src, size);
	printf("Concatenated String: %s\n", dest);
	printf("Result: %zu\n", result);
	return 0;
}
*/