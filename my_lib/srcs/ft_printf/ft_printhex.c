/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:26:47 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:12 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_prefix(int upper)
{
	if (upper == 1)
		ft_putstr_fd_m("0X", 1);
	else
		ft_putstr_fd_m("0x", 1);
	return (2);
}

int	ft_print_x(char *s, int nbr, int upper, t_flags flag)
{
	int	i;

	i = 0;
	if (!flag.zero && flag.hash == 1 && nbr)
		i += ft_prefix(upper);
	if (flag.precision >= 0)
		i += ft_pad(flag.precision - 1,
				ft_strlen(s) - 1, 1);
	i += ft_putstr_fd_m(s, 1);
	return (i);
}

int	ft_print_hexadec(char *s, int nbr, int upper, t_flags flag)
{
	int	i;

	i = 0;
	if (flag.zero == 1 && flag.hash == 1 && nbr)
		i += ft_prefix(upper);
	if (flag.left == 1)
		i += ft_print_x(s, nbr, upper, flag);
	if (flag.precision >= 0 && (size_t)flag.precision < ft_strlen(s))
		flag.precision = ft_strlen(s);
	if (flag.precision >= 0)
	{
		flag.width -= flag.precision;
		i += ft_pad(flag.width, 0, 0);
	}
	else
		i += ft_pad(flag.width,
				ft_strlen(s) + (flag.hash * 2), flag.zero);
	if (!flag.left)
		i += ft_print_x(s, nbr, upper, flag);
	return (i);
}

size_t	ft_printhex(unsigned int nbr, int upper, t_flags flag)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!flag.precision && !nbr)
	{
		i += ft_pad(flag.width, 0, 0);
		return (i);
	}
	s = ft_xtoa(nbr, upper);
	if (!s)
		return (0);
	i += ft_print_hexadec(s, nbr, upper, flag);
	free(s);
	return (i);
}
