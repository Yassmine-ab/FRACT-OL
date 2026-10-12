/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:48:04 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/21 05:41:31 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*
The ft_remaining_text function returns a new string rem that contains the
remaining text after the first newline character in the input string s.
*/

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
/*
The ft_read_line function reads from the file descriptor fd into a line_buffer,
then appends the line_buffer to the rem variable.
line_buffer is a pointer to a memory block of size BUFFER_SIZE + 1, where are
stored the characters read from the file.
BUFFER_SIZE is the maximum number of bytes to read at a time.
The loop continues until the store string contains a newline character.
*/

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
/*
The ft_extract_line function returns a new string line that
contains the text before the first newline character (including it)
from the input string store.
The content after the first newline character is stored into the store
variable.
*/

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*temp;
	char		*line;
	int			read_count;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = NULL;
	line = NULL;
	read_count = 1;
	ft_read_line(fd, &rem, &temp, read_count);
	if (rem && *rem)
		line = ft_extract_line(&rem, &temp);
	if (!line || !*line)
	{
		ft_free(&line);
		ft_free(&rem);
		ft_free(&temp);
		return (NULL);
	}
	return (line);
}
/*
The get_next_line function reads a text file pointed to
by the file descriptor, one line at a time. It returns the
line read from the file with the terminating newline character,
except if the end of file was reached.
If there is nothing else to read, or if an error occurred, it returns NULL.
It uses a static variable rem to store the remaining text from the file
between function calls.
This allows the function to continue reading from where it left off in the
previous call.
*/
