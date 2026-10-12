/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:23:25 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:17 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_print_i(char *s, int nbr, t_flags flag)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		if (!flag.zero || flag.precision >= 0)
			i += ft_putchar_fd_m('-', 1);
	}
	else if (flag.plus == 1 && !flag.zero)
		i += ft_putchar_fd_m('+', 1);
	else if (flag.space == 1 && !flag.zero)
		i += ft_putchar_fd_m(' ', 1);
	if (flag.precision >= 0)
		i += ft_pad(flag.precision - 1, ft_strlen(s) - 1, 1);
	i += ft_putstr_fd_m(s, 1);
	return (i);
}

size_t	ft_print_sign(int nbr, t_flags *flag)
{
	size_t	i;

	i = 0;
	if (nbr < 0 && flag->precision == -1)
	{
		i += ft_putchar_fd_m('-', 1);
		flag->width--;
	}
	else if (flag->plus == 1)
		i += ft_putchar_fd_m('+', 1);
	else if (flag->space == 1)
	{
		i += ft_putchar_fd_m(' ', 1);
		flag->width--;
	}
	return (i);
}

size_t	ft_print_integer(char *s, int nbr, t_flags flag)
{
	size_t	i;

	i = 0;
	if (flag.zero == 1)
		i += ft_print_sign(nbr, &flag);
	if (flag.left == 1)
		i += ft_print_i(s, nbr, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(s))
		flag.precision = ft_strlen(s);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		if (nbr < 0 && !flag.left)
			flag.width -= 1;
		i += ft_pad(flag.width, 0, 0);
	}
	else
		i += ft_pad(flag.width - flag.plus - flag.space,
				ft_strlen(s), flag.zero);
	if (!flag.left)
		i += ft_print_i(s, nbr, flag);
	return (i);
}

size_t	ft_printint(int nbr, t_flags flag)
{
	size_t	i;
	char	*s;
	long	nb;

	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (!flag.zero)
			flag.width--;
	}
	if (!flag.precision && !nbr)
	{
		i += ft_pad(flag.width, 0, 0);
		return (i);
	}
	s = ft_itoa_m(nb);
	if (!s)
		return (0);
	i += ft_print_integer(s, nbr, flag);
	free(s);
	return (i);
}
