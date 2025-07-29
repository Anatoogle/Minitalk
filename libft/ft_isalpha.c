/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:37:50 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:31 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '-';
// 	printf("%d\n", isalpha(c));
// 	printf("%d", ft_isalpha(c));
// }

/*
the return value is 1024,
which is a bit unusual since you'd expect 1
if you're thinking in terms of a simple true/false check.

it can be any positive integer, and 1024 is a common return value
in some environments when the result is true
*/