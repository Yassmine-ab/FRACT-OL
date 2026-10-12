/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:38:56 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:14:40 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_print_type(char type, va_list ptrs, t_flags flag)
{
	size_t	i;

	i = 0;
	if (type == 'c')
		i += ft_printchar(va_arg(ptrs, int), flag);
	else if (type == 's')
		i += ft_printstr(va_arg(ptrs, const char *), flag);
	else if (type == 'p')
		i += ft_printptr((unsigned long int)va_arg(ptrs, void *), flag);
	else if (type == 'd' || type == 'i')
		i += ft_printint(va_arg(ptrs, int), flag);
	else if (type == 'u')
		i += ft_printuns(va_arg(ptrs, unsigned int), flag);
	else if (type == 'x')
		i += ft_printhex(va_arg(ptrs, unsigned int), 0, flag);
	else if (type == 'X')
		i += ft_printhex(va_arg(ptrs, unsigned int), 1, flag);
	else if (type == '%')
		i += ft_printchar('%', flag);
	return (i);
}
/*
The function acts as a dispatcher for the different print functions based on
the provided type. It returns the number of characters printed.
*/

static size_t	ft_check_flag(char *s, size_t i, va_list ptrs, t_flags *flag)
{
	while (s[++i] && ft_isspec(s[i]))
	{
		if (s[i] == '-')
			*flag = ft_flag_left(*flag);
		if (s[i] == '#')
			flag->hash = 1;
		if (s[i] == ' ')
			flag->space = 1;
		if (s[i] == '+')
			flag->plus = 1;
		if (s[i] == '0' && !flag->left && !flag->width)
			flag->zero = 1;
		if (s[i] == '.')
			i = ft_flag_precision(s, i, ptrs, flag);
		if (s[i] == '*')
			*flag = ft_flag_width(ptrs, *flag);
		if (ft_isdigit(s[i]))
			*flag = ft_flag_digit(s[i], *flag);
		if (ft_isconv(s[i]))
		{
			flag->conv = s[i];
			break ;
		}
	}
	return (i);
}
/*
This function checks for flags, width, precision, and conversion specifiers.
It returns the index of the specifier.
*/

size_t	ft_check_format(char *s, va_list ptrs)
{
	size_t	i;
	size_t	j;
	size_t	k;
	t_flags	flag;

	i = -1;
	k = 0;
	while (s[++i])
	{
		flag = ft_flag_start();
		if (s[i] == '%' && s[i + 1])
		{
			j = ft_check_flag(s, i, ptrs, &flag);
			if (flag.conv > 0 && ft_isconv(s[i]))
			{
				i = j;
				k += ft_print_type(s[i], ptrs, flag);
			}
		}
		else
			k += ft_putchar_fd_m(s[i], 1);
	}
	return (k);
}
/*
This function iterates through the string and checks for the presence
of flags, width, precision, and conversion specifiers.
*/
