/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:16:50 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:42:16 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strrchr libc function is used to find the last occurrence
of a specific character (searchedChar) in a string (*string).
*/
#include "../../includes/libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string) + 1;
	while (--i >= 0)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i]);
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("strrchr: %s\n", strrchr("Hello guys", 'u'));
 	printf("ft_strrchr: %s\n", ft_strrchr("Hello guys", 'u'));
	return (0);
}
*/
