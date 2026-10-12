/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:22:40 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:14:46 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_hexlen(size_t nbr)
{
	size_t	len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}
/*
This function calculates the length of a given number in hexadecimal.
*/
