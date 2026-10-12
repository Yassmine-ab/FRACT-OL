/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:11:40 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 20:50:55 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The itoa function stands for "integer to ASCII" and
is used to convert an integer (n) into a string (str).
*/
#include "../../includes/ft_printf.h"

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

char	*ft_itoa_m(long nbr)
{
	size_t	len;
	char	*str;

	len = ft_len(nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (--len)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (str[0] != '-')
		str[0] = nbr % 10 + '0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("itoa: %s\n", itoa(-2147483648));
	printf("ft_itoa_m: %s\n", ft_itoa_m(-2147483648));
	return (0);
}
*/
