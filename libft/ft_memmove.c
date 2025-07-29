/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:29:30 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 14:22:32 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

// int	main(void)
// {
// 	char	s[] = "Hello, World!";

// 	ft_memmove(s + 7, s, 5);
// 	printf("%s", s);
// }

/*
memmove
	If the destination (d) is located at a higher memory address
	than the source (s), this indicates that the memory blocks may overlap

	therefore start from the back
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];

	if the destination (d) is before (a), than start from the beginning
	i = 0;
	else
	while (i < len)
	{
		d[i] = s[i];
		i++;
*/