/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:23:32 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/09 21:36:10 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	char	*str;
	va_list	ptrs;

	i = 0;
	str = ft_strdup(s);
	if (!str)
		return (-1);
	va_start(ptrs, s);
	i = (int)ft_check_format(str, ptrs);
	va_end(ptrs);
	free(str);
	return (i);
}
/*
ft_printf is a variadic function that takes a string *s
and a variable number of arguments.
ptrs is a pointer to the last fixed argument *s.
va_start initializes the va_list ptrs to the first variable argument.
va_end frees the memory allocated for the va_list ptrs.
*/
