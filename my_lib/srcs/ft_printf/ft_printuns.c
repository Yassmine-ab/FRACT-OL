/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:55:54 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:27 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_print_unint(char *s, t_flags flag)
{
	size_t	i;

	i = 0;
	if (flag.left == 1)
	{
		if (flag.precision >= 0)
			i += ft_pad(flag.precision - 1, ft_strlen(s) - 1, 1);
		i += ft_putstr_fd_m(s, 1);
	}
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(s))
		flag.precision = ft_strlen(s);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		i += ft_pad(flag.width, 0, 0);
	}
	else
		i += ft_pad(flag.width, ft_strlen(s), flag.zero);
	if (flag.left == 0)
	{
		if (flag.precision >= 0)
			i += ft_pad(flag.precision - 1, ft_strlen(s) - 1, 1);
		i += ft_putstr_fd_m(s, 1);
	}
	return (i);
}

size_t	ft_printuns(unsigned int nbr, t_flags flag)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!flag.precision && !nbr)
	{
		i += ft_pad(flag.width, 0, 0);
		return (i);
	}
	s = ft_utoa(nbr);
	if (!s)
		return (0);
	i += ft_print_unint(s, flag);
	free(s);
	return (i);
}
/*
This function prints an unsigned integer with various formatting options
specified by the t_flags structure.
It handles cases where the precision is not set, adjusts the width based
on the precision value, and prints the number in the correct order based
on the flag.left flag.
*/
