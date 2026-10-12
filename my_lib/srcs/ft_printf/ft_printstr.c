/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:55:42 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:25 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_print_string(const char *s, t_flags flag)
{
	size_t	i;

	i = 0;
	if (flag.precision >= 0)
	{
		i += ft_pad(flag.precision, ft_strlen(s), 0);
		while (s[i] && i < (size_t)flag.precision)
			write(1, &s[i++], 1);
	}
	else
		while (s[i] && i < ft_strlen(s))
			write(1, &s[i++], 1);
	return (i);
}

size_t	ft_printstr(const char *s, t_flags flag)
{
	size_t	i;

	i = 0;
	if (s == NULL && flag.precision >= 0 && flag.precision < 6)
	{
		i += ft_pad(flag.width, 0, 0);
		return (i);
	}
	if (s == NULL)
		s = "(null)";
	if (flag.precision >= 0 && (size_t)flag.precision > ft_strlen(s))
		flag.precision = ft_strlen(s);
	if (flag.left == 1)
		i += ft_print_string(s, flag);
	if (flag.precision >= 0)
		i += ft_pad(flag.width, flag.precision, 0);
	else
		i += ft_pad(flag.width, ft_strlen(s), 0);
	if (flag.left == 0)
		i += ft_print_string(s, flag);
	return (i);
}
