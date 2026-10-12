/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:00:19 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:11:08 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The bzero libc function is used to set a number of bytes (n) in
a block of memory (*s) to zero.
*/
#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(char *)(s + i) = '\0';
}
/*
Casting s + i to a char pointer to ensure that the operation is performed
on a byte-by-byte basis, and dereferencing it to assign 0.
*/
