/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:14:51 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:43:36 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strchr libc function is used to find the first occurrence of
a specific character (searchedChar) in a string (*string).
*/
#include "../../includes/libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i]);
	}
	if (string[i] == (char)searchedChar)
		return ((char *)&string[i]);
	return (NULL);
}
/*
The function checks one more time after the loop for
the null terminator if it matches the searched character.

#include <stdio.h>

int	main(void)
{
	printf("Result: %s\n", ft_strchr("Bonjour salut les gars", 'a'));
	return (0);
}
*/