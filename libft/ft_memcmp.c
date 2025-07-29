/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:09 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:45:29 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1value;
	const unsigned char	*s2value;
	size_t				i;

	s1value = (const unsigned char *)s1;
	s2value = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1value[i] != s2value[i])
			return (s1value[i] - s2value[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	src[10] = "Hell0";
// 	char	dst[10] = "Hell0";

// 	printf("%d\n", ft_memcmp(src, dst, 5));
// }

/*
i++ vs ++i

int	i = 5;
int	x = i++;  // x gets 5, then i becomes 6

int	i = 5;
int	x = ++i;  // i becomes 6, then x gets 6

will give same result, could only performance difference?
++i could be slightly more efficient because i++ may involve
creating a temporary copy of the old value before incrementing.
*/