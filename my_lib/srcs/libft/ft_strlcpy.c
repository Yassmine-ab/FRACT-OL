/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:15:36 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:13:36 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlcpy libc function is used to copy a string from a source (*src)
to a destination (*dest).
*/
#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size > 0)
	{
		while (++i < (size - 1) && src[i])
			dest[i] = src[i];
		dest[i] = '\0';
	}
	else
		i++;
	while (src[i])
		i++;
	return (i);
}
