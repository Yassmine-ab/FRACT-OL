/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:17:11 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:41:59 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The tolower libc function is used to convert an uppercase letter (c)
to its corresponding lowercase letter.
*/
#include "../../includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
	printf("tolower: %d\n", tolower('a'));
	printf("ft_tolower: %d\n", ft_tolower('a'));
	return (0);
}
*/
