/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:55:38 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/07 17:09:40 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_strjoin function concatenates two strings (*s1 and *s2) into
a new string (*s).
*/
#include "../../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, s1_len + 1);
	ft_strlcat(s + s1_len, s2, s2_len + 1);
	return (s);
}
/*
#include <stdio.h>
#include <stdio.h>

int	main(void)
{
	printf("strjoin: %p\n", strjoin(5, 5));
 	printf("ft_strjoin: %s\n", ft_strjoin("Hello, ", "world !"));
 	return (0);
}
*/