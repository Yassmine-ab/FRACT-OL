/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:47:40 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/20 00:18:31 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// GET_NEXT_LINE
char	*get_next_line(int fd);
char	*ft_extract_line(char **store, char **temp);
void	ft_read_line(int fd, char **store, char **temp, int read_count);
char	*ft_remaining_text(const char *s);

// HELPER
int		ft_newline(const char *s);
char	*ft_strdup_m(const char *s1);
void	ft_free(char **s);

#endif