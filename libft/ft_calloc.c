/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:35:48 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:54:37 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*d;
	size_t			total;

	if (nmemb > (size_t)-1 / size)
		return (0);
	total = nmemb * size;
	d = malloc(total);
	if (!d)
		return (0);
	ft_memset(d, 0, total);
	return (d);
}

// int	main(void)
// {
// 	size_t	a;
// 	size_t	b;
// 	char	*s1;
// 	char	*s2;

// 	a = 2;
// 	b = 2;
// 	// s1 = calloc(a, b);
// 	s2 = ft_calloc(a, b);
// 	printf("%p\n", &s1);
// 	printf("%p\n", &s2);
// }

/*
Overflow
	If you're using a data type like int and trying to store a value larger
		than the maximum size of that data type will cause an overflow.
	int max_value = INT_MAX; and you try to compute max_value + 1
		this will cause the value to wrap around and become negative

(size_t)-1
	get the max value of size_t (only works for that, not for int).
if (nmemb > (size_t)-1 / size)
*/