/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:40 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 12:06:37 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	char	*c;

// 	c = "12345 789";
// 	printf("%lu\n", strlen(c));
// 	printf("%d", ft_strlen(c));
// }
