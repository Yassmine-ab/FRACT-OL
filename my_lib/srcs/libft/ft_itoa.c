/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:11:40 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:11:29 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The itoa function stands for "integer to ASCII" and
is used to convert an integer (n) into a string (str).
*/
#include "../../includes/libft.h"

static size_t	ft_len(long n)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	len;
	char	*str;

	nbr = (long)n;
	len = ft_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[len] = '\0';
	while (nbr > 0)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("itoa: %s\n", itoa(-2147483648));
	printf("ft_itoa: %s\n", ft_itoa(-2147483648));
	return (0);
}
*/
