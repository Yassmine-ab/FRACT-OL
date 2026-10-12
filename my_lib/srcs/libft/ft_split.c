/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:13:48 by yaabdall          #+#    #+#             */
/*   Updated: 2024/08/24 21:43:46 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_split function splits a string (*s) into an array
of substrings (**tab_str), using a specified character (c) as the delimiter.
*/
#include "../../includes/libft.h"

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static char	**ft_free(char **s, size_t i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab_str;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	tab_str = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab_str)
		return (NULL);
	while (++i < ft_nb_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		tab_str[i] = ft_substr(s, j, ft_word_len(&s[j], c));
		if (!tab_str[i])
			return (ft_free(tab_str, i));
		while (s[j] && s[j] != c)
			j++;
	}
	tab_str[i] = NULL;
	return (tab_str);
}
/*
At the end of each loop, the pointer s is moved forward
by the length of the word.

#include <stdio.h>

int	main(int ac, char **av)
{
	char 	**tab;
	int	i;
	
	i = 0;
	(void)ac;
	tab = ft_split(av[1], av[2][0]);
	if (tab == NULL)
	{
		free(tab);
		printf("error");
		return (0);
	}
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%s\n", tab[i]);
	free_tab(tab, av[1], av[2][0]);
}*/