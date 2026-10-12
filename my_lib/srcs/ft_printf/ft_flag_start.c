/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:22:16 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:14:43 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_flags	ft_flag_start(void)
{
	t_flags	flag;

	flag.conv = 0;
	flag.width = 0;
	flag.left = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.precision = -1;
	flag.hash = 0;
	flag.space = 0;
	flag.plus = 0;
	return (flag);
}
/*
This function initializes the flags sucture.
*/

t_flags	ft_flag_left(t_flags flag)
{
	flag.left = 1;
	flag.zero = 0;
	return (flag);
}
/*
This function left justifies the output if the '-' flag is present.
*/

t_flags	ft_flag_digit(char c, t_flags flag)
{
	if (flag.star == 1)
		flag.width = 0;
	flag.width = (flag.width * 10) + c - '0';
	return (flag);
}
/*
This function sets the width flag to the given digit.
*/

t_flags	ft_flag_width(va_list ptrs, t_flags flag)
{
	flag.star = 1;
	flag.width = va_arg(ptrs, int);
	if (flag.width < 0)
	{
		flag.left = 1;
		flag.width *= -1;
	}
	return (flag);
}
/*
This function sets the width flag to the value of the next argument
if the '*' flag is present.
*/

size_t	ft_flag_precision(const char *s, size_t j, va_list ptrs, t_flags *flag)
{
	size_t	i;

	i = j + 1;
	if (s[i] == '*')
	{
		flag->precision = va_arg(ptrs, int);
		return (i++);
	}
	flag->precision = 0;
	while (ft_isdigit(s[i]))
	{
		flag->precision = (flag->precision * 10) + s[i] - '0';
		i++;
	}
	return (i);
}
/*
This function sets the precision flag to the value of the next argument
if the '*' flag is present. j is the position of the '.' flag.
*/
