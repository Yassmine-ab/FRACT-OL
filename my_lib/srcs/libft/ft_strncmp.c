/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:16:00 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:42:27 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strncmp libc function is used to compare the first characters (len)
of two strings (*s1 and *s2).
*/
#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!len)
		return (0);
	while (i < (len - 1) && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("strncmp: %d\n", strncmp("Hello guys", "Hello fuys", 10));
	printf("ft_strncmp: %d\n", ft_strncmp("Hello guys", "Hello fuys", 10));
	return (0);
}
*/
