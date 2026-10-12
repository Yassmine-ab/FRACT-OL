/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdall <yaabdall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:25:52 by yaabdall          #+#    #+#             */
/*   Updated: 2024/09/20 00:19:05 by yaabdall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# if defined (__linux__)
#  define PTR_NULL "(nil)"
# endif

// FLAGS STRUCTURE
typedef struct s_flags
{
	int	conv;
	int	left;
	int	zero;
	int	precision;
	int	width;
	int	star;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

// FLAGS FUNCTIONS
t_flags	ft_flag_start(void);
t_flags	ft_flag_left(t_flags flag);
t_flags	ft_flag_digit(char c, t_flags flag);
t_flags	ft_flag_width(va_list ptrs, t_flags flag);
size_t	ft_flag_precision(const char *s, size_t j, va_list ptrs, t_flags *flag);
size_t	ft_pad(int set_width, int size, int zero);

// PRINTF FINAL FUNCTIONS
int		ft_printf(const char *s, ...);
size_t	ft_check_format(char *s, va_list ptrs);

// CONVERSIONS FUNCTIONS
// %c
size_t	ft_printchar(char c, t_flags flag);
// %s
size_t	ft_printstr(const char *s, t_flags flag);
// %p
size_t	ft_printptr(unsigned long int nbr, t_flags flag);
void	ft_print_adr(unsigned long int nbr);
// %d and %i
size_t	ft_printint(int nbr, t_flags flag);
size_t	ft_print_integer(char *s, int nbr, t_flags flag);
size_t	ft_print_i(char *s, int nbr, t_flags flag);
size_t	ft_print_sign(int nbr, t_flags *flag);
// %u
size_t	ft_printuns(unsigned int nbr, t_flags flag);
// %x and %X
size_t	ft_printhex(unsigned int nbr, int upper, t_flags flag);
int		ft_print_x(char *s, int nbr, int upper, t_flags flag);
int		ft_print_hexadec(char *s, int nbr, int upper, t_flags flag);

// SUPPORT FUNCTIONS
char	*ft_utoa(size_t nbr);
char	*ft_xtoa(size_t nbr, int upper);
size_t	ft_nbrlen(long nbr);
size_t	ft_hexlen(size_t nbr);
int		ft_isconv(int c);
int		ft_isflag(int c);
int		ft_isspec(int c);

// MODIFIED LIBFT FUNCTIONS
char	*ft_itoa_m(long nbr);
size_t	ft_putchar_fd_m(char c, int fd);
size_t	ft_putstr_fd_m(char *s, int fd);

#endif