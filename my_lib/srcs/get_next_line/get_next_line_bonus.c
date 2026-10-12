/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:47:30 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/21 05:41:08 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_remaining_text(const char *s)
{
	char	*rem;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
		i++;
	j = 0;
	while (s[j] && s[j] != '\n')
		j++;
	if (s[j] == '\n')
		j++;
	rem = ft_calloc(i - j + 1, sizeof(char));
	if (!rem)
		return (NULL);
	i = -1;
	while (s[++i + j])
		rem[i] = s[i + j];
	return (rem);
}

void	ft_read_line(int fd, char **rem, char **temp, int read_count)
{
	char	*line_buffer;

	line_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line_buffer)
		return ;
	while (read_count)
	{
		read_count = read(fd, line_buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			ft_free(&line_buffer);
			ft_free(rem);
			ft_free(temp);
			return ;
		}
		line_buffer[read_count] = '\0';
		*temp = ft_strdup_m(*rem);
		ft_free(rem);
		*rem = ft_strjoin(*temp, line_buffer);
		ft_free(temp);
		if (ft_newline(*rem))
			break ;
	}
	ft_free(&line_buffer);
}

char	*ft_extract_line(char **rem, char **temp)
{
	size_t	i;
	char	*line;

	i = 0;
	*temp = ft_strdup_m(*rem);
	if (!*temp)
		return (NULL);
	ft_free(rem);
	*rem = ft_remaining_text(*temp);
	while ((*temp)[i] && (*temp)[i] != '\n')
		i++;
	if ((*temp)[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while ((*temp)[++i] && (*temp)[i] != '\n')
		line[i] = (*temp)[i];
	if ((*temp)[i] == '\n')
		line[i] = (*temp)[i];
	ft_free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rem[1024];
	char		*temp;
	char		*line;
	int			read_count;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = NULL;
	line = NULL;
	read_count = 1;
	ft_read_line(fd, &rem[fd], &temp, read_count);
	if (rem[fd] && *rem[fd])
		line = ft_extract_line(&rem[fd], &temp);
	if (!line || !*line)
	{
		ft_free(&line);
		ft_free(&rem[fd]);
		ft_free(&temp);
		return (NULL);
	}
	return (line);
}
