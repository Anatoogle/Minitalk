/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:22 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/04 10:07:59 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
size_t		ft_hexlen(size_t num);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_putunsignednbr(unsigned int n);
char		*ft_printhex(unsigned int ptr, int len, char *ftype);
int			ft_putptr(size_t ptr);
char		*ft_strptr(size_t ptr, int len);
int			ft_puthex(unsigned int ptr, char *ftype);

#endif

/*
(unsigned long long)
	long:
		This is typically 4 bytes on a 32-bit system,
			but it can be 8 bytes on a 64-bit system,depending
			on the platform (e.g.,
			UNIX-like systems often define long as 8 bytes).
	long long:
		This is a type guaranteed to be at least 8 bytes on all systems,
			regardless of whether you're on a 32-bit or 64-bit system.
*/

/*
typedef struct s_plist
{
	int		width;
	int		precision;
	char	flags;
	char	specifier;
}			t_plist;

Struct Fields:

width			specifies the minumum nuber of characters to print
				if the printed value is shorter than the specific width,
				it will be padded with spaces (or zeros depending on flags)

precision		specifies the number of digits to print for numbers or the
				maximum	numberr of characters for string. 0 would print no
				characters for a string

flags			used to modify the output behaviour,
				such as left-justification (-),
				zero-padding (0), or forcing a sign (+)

specifier		specifies the type of value to print (eg., c, s, p, i, u, x,
			X or %)


*/
