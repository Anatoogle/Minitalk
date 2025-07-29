/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:24:51 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:42:53 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[11] = "hello world";

// 	printf("%s\n", str);
// 	ft_memset(str, '#', 3);
// 	printf("%s\n", str);
// }

// 	while (n--)
// 	{
// 		*ptr = (unsigned char)c;
// 		ptr++;
// 	}

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	*ptr;
// 	size_t			i;
// 	i = 0;
// 	ptr = s;
// 	while (i < n)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (s);
// }

/*
unsigned char   can only represent positive values (0–255).
signed char     can represent both positive and negative values
				(-128 to 127).

memset should work with any type of data. for general-purpose
memory manipulation, unsigned char is used to ensure that all
byte values are handled consistently ensure


void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		*s = (char)c;
		s++;
		n--;
	}
	return (s);
}

void *s
	A void * pointer is a generic pointer type in C,
		meaning it has no specific type
	associated with it,
		and the compiler doesn't know the size or layout of the memory
	it points to. Therefore, dereferencing a void
		* is not allowed in C because it
	doesn't have a defined size.

	To use a void * for dereferencing, you need to cast it to a specific type
	(such as char *, int *, or unsigned char *),
		depending on the kind of memory you're dealing with.

	void * allows you to write functions that can work with any data type
	It makes the function flexible and able to operate on memory blocks of
	any type (whether it's an array of int, char, double, etc.).

void *ft_memset
	indicate that the function returns a pointer.
	This means that the function will return a pointer to void,
	i.e., a pointer that points to some unspecified type of data.

*
	The asterisk is used to indicate that the type is a pointer

dereferencing
	refers to accessing or modifying the value that a pointer is pointing to.

*/