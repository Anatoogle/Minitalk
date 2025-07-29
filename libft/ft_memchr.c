/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:03 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:47:43 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sdest;
	size_t				i;

	sdest = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sdest[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	src[10] = "Hello";
// 	char	*ptr;

// 	// ptr = memchr(src, 'e', 5);
// 	ptr = ft_memchr(src, 'l', 5);
// 	printf("%s\n", ptr);
// }
