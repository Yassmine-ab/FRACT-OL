/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:02:28 by yaabdall          #+#    #+#             */
/*   Updated: 2024/10/12 01:21:41 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Handles negative numbers and return the integer part as a string
static char	*handle_negative(double *n)
{
	char	*integer_str;
	char	*itoa_str;

	integer_str = NULL;
	if (*n < 0)
	{
		*n = -*n;
		itoa_str = ft_itoa((long)*n);
		if (!itoa_str)
			return (NULL);
		integer_str = ft_strjoin("-", itoa_str);
		free(itoa_str);
		if (!integer_str)
			return (NULL);
	}
	else
	{
		integer_str = ft_itoa((long)*n);
		if (!integer_str)
			return (NULL);
	}
	return (integer_str);
}

// Calculates 10^precision (used for fractional conversion)
static long	calculate_pow10(int precision)
{
	long	pow10;
	int		i;

	pow10 = 1;
	i = -1;
	while (++i < precision)
		pow10 *= 10;
	return (pow10);
}

// Converts fractional part to string with fixed precision
static char	*convert_fractional(double fractional_part, int precision)
{
	long	fract_as_int;
	char	*fractional_str;

	fract_as_int = (long)(fractional_part * calculate_pow10(precision) + 0.5);
	fractional_str = ft_itoa(fract_as_int);
	return (fractional_str);
}

// Main function to convert double to string
char	*ft_ftoa(double n, int precision)
{
	char	*integer_str;
	char	*fractional_str;
	char	*result;
	char	*tmp;
	long	integer_part;

	integer_str = handle_negative(&n);
	if (!integer_str)
		return (NULL);
	integer_part = (long)n;
	double (fractional_part) = n - (double)integer_part;
	fractional_str = convert_fractional(fractional_part, precision);
	if (!fractional_str)
		return (free(integer_str), NULL);
	tmp = ft_strjoin(integer_str, ".");
	free(integer_str);
	if (!tmp)
		return (free(fractional_str), NULL);
	result = ft_strjoin(tmp, fractional_str);
	free(tmp);
	free(fractional_str);
	return (result);
}
