/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:23:06 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:08 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_printchar(char c, t_flags flag)
{
	size_t	i;

	i = 0;
	if (flag.left == 1)
		i += ft_putchar_fd_m(c, 1);
	i += ft_pad(flag.width, 1, flag.zero);
	if (!flag.left)
		i += ft_putchar_fd_m(c, 1);
	return (i);
}
/*
This function prints a character c with optional padding and
alignment based on the t_flags structure.
*/
