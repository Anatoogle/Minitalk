/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:41:03 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/04 10:00:53 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printargs(char format, va_list *args)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (format == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (format == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (format == 'p')
		count = ft_putptr(va_arg(*args, size_t));
	else if (format == 'u')
		count = ft_putunsignednbr(va_arg(*args, unsigned int));
	else if (format == '%')
		count = ft_putchar('%');
	else if (format == 'x')
		count = ft_puthex(va_arg(*args, unsigned int), "lower");
	else if (format == 'X')
		count = ft_puthex(va_arg(*args, unsigned int), "upper");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	mylist;
	int		len_print;
	int		i;

	i = 0;
	len_print = 0;
	va_start(mylist, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len_print += ft_printargs(format[i + 1], &mylist);
			i++;
		}
		else
			len_print += ft_putchar(format[i]);
		i++;
	}
	va_end(mylist);
	return (len_print);
}

/*
- printf is a variadic function,
	meaning it can take a variable number of arguments

- va_start
	Purpose: Initializes the variable argument list.
- va_arg
	Retrieves an argument from the list.
	Accesses the next argument in the list.
- va_copy
	Purpose: Creates a copy of a va_list for use in a separate context.
- va_end
	Purpose: Cleans up after the variadic arguments have been accessed.

*/

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/