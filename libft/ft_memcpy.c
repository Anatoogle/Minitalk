/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:51 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 14:21:44 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*vdest;
	const unsigned char	*vsrc;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	vdest = dest;
	vsrc = src;
	while (i < n)
	{
		vdest[i] = vsrc[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[10] = "Hello";
// 	char	dest[10] = "Neinn";

// 	printf("%s\n", src);
// 	printf("%s\n", dest);
// 	// memcpy(dest, src, 2);
// 	ft_memcpy(dest, src, 5);
// 	printf("%s\n", src);
// 	printf("%s\n", dest);
// }

/*
void	*ft_memcpy(void *dest, const void *src, size_t n)

const
	Keyword that specifics that the data should not be modified.
	The function promises not to change the contents of that memory
	This is a safety feature to ensure the content wont accidentally get changed

*/
