/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:35:43 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 12:48:12 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int	main(void)
// {
// 	char	dst[] = "World";
// 	char	src[] = "Hallo";

// 	ft_strlcpy(dst, src, 5);
// 	printf("%s\n", dst);
// }

/*
Difference strlcpy / strncpy

Null-termination:
	strncpy does not guarantee null-termination
		(unless the source is shorter than n)
	strlcpy always null-terminates the destination
		(as long as the destination buffer size is non-zero)

Buffer size handling:
	strncpy can potentially overwrite the destination buffer or
		fail to null-terminate it
	strlcpy ensures that the destination buffer is null-terminated and
		does not overflow the buffer (if size is respected)

Return value:
	strncpy returns a pointer to the destination
	strlcpy returns the total length of the source string
		(not the number of characters copied)


size_t
	is an unsigned data type, typically used to represent the size of
	objects in memory or array indices.

int
	is a general-purpose integer type used to store signed integers.
	It can represent both positive and negative numbers.
*/