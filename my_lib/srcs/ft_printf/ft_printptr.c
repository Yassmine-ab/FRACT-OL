/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:23:37 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:20 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_print_adr(unsigned long int nbr)
{
	if (nbr >= 16)
	{
		ft_print_adr(nbr / 16);
		ft_print_adr(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar_fd_m(nbr + '0', 1);
		else if (nbr >= 10)
			ft_putchar_fd_m(nbr + 'a' - 10, 1);
	}
}

size_t	ft_printptr(unsigned long int nbr, t_flags flag)
{
	size_t	i;

	i = 0;
	if (!nbr)
		flag.width -= ft_strlen(PTR_NULL) - 1;
	else
		flag.width -= 2;
	if (flag.left == 1)
	{
		i += ft_putstr_fd_m("0x", 1);
		ft_print_adr(nbr);
		i += ft_hexlen(nbr);
	}
	i += ft_pad(flag.width, ft_hexlen(nbr), 0);
	if (!flag.left)
	{
		if (!nbr)
			return (i += ft_putstr_fd_m(PTR_NULL, 1));
		i += ft_putstr_fd_m("0x", 1);
		ft_print_adr(nbr);
		i += ft_hexlen(nbr);
	}
	return (i);
}
