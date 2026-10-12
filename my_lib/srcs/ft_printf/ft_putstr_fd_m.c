/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:08:34 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:33 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_putstr_fd function is used to write a string (*s)
to a file descriptor (fd).
*/
#include "../../includes/ft_printf.h"

size_t	ft_putstr_fd_m(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (s[++i])
		ft_putchar_fd_m(s[i], fd);
	return (i);
}
