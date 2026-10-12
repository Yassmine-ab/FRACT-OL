/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:15:12 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/16 21:51:50 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup libc function is used to create a duplicate of a string (*s1).
It allocates memory for the new string (*str) and then copies
the original string into the newly allocated memory.
*/
#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*str;

	if (!s1)
		return (ft_strdup(""));
	i = -1;
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
