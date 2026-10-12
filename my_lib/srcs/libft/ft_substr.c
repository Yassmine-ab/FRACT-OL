/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:37:33 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:42:05 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The substr libc function allocates (with malloc) and
returns a substring (*str) from a given string (*s).
The substring begins at index (start) and is of maximum size (len).
*/
#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = -1;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len < start)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("substr : %s\n", substr("Hello guys how are you?", 3, 10));
	printf("ft_substr : %s\n", ft_substr("Hello guys how are you?", 3, 10)););
	return (0);
}
*/
