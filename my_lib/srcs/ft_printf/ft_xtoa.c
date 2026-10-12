/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:27:22 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/08 23:15:37 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_xtoa(size_t nbr, int upper)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = -1;
	len = ft_hexlen(nbr);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (--len != (size_t)-1)
	{
		if ((nbr % 16) < 10)
			s[len] = (nbr % 16) + '0';
		else if ((nbr % 16) >= 10)
			s[len] = (nbr % 16) - 10 + 'a';
		nbr /= 16;
	}
	while (s[++i])
	{
		if (s[i] >= 'a' && s[i] <= 'f' && upper == 1)
			s[i] -= 32;
	}
	return (s);
}
