/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:16:35 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:42:22 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strnstr libc function is used to find the first occurrence of a
substring (little) in a larger string (big),
considering only the first characters (len) of big.
*/
#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len >= little_len)
	{
		if (*big == *little
			&& !ft_strncmp(big, little, little_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("strnstr: %s\n", strstr("Hello guys how are you ?", "how", 18));
	printf("ft_strnstr: %s\n", ft_strnstr("Hello guys how are you?", "how", 18));
	return (0);
}
*/
