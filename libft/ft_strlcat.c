/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:16:56 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 12:59:01 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && dlen + i < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char dst[20] = "Hello, ";
// 	const char *src = "world!";

// 	size_t result = ft_strlcat(dst, src, 9);
// 	printf("%s\n", dst);
// 	printf("%zu\n", result);

// 	return (0);
// }

/*
It concatenates the string src to the end of dst,
ensuring that dst has enough space to hold both strings,
	plus the null terminator.

returns
	the total length of the string it tried to create,
	which is the length of the original string in dst plus the length of src.
*/