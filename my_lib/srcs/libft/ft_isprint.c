/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:06:26 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:11:24 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isprint libc function is used to check if a given character (c) is printable.
*/
#include "../../includes/libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
