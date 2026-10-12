/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:22:54 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:06 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_pad(int set_width, int size, int zero)
{
	size_t	i;

	i = 0;
	while (set_width - size > 0)
	{
		if (zero)
			i += ft_putchar_fd_m('0', 1);
		else
			i += ft_putchar_fd_m(' ', 1);
		set_width--;
	}
	return (i);
}
/*
This function pads a given width with either spaces or zeros, depending
on the flag zero.
*/
