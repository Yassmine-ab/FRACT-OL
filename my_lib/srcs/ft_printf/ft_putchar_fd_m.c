/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:07:46 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:30 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_putchar_fd function is used to write a character (c)
to a file descriptor (fd).
*/
#include "../../includes/ft_printf.h"

size_t	ft_putchar_fd_m(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
