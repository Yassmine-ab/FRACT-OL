/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:47:48 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/21 05:41:14 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_newline(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strdup_m(const char *s1)
{
	size_t	i;
	char	*s2;

	if (!s1)
		return (ft_strdup_m(""));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_calloc(i + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	return (s2);
}

void	ft_free(char **s)
{
	if (!s || !*s)
		return ;
	free(*s);
	*s = NULL;
}
