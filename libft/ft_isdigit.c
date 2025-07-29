/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:57:54 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:28 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '9';
// 	printf("%d\n", isdigit(c));
// 	printf("%d", ft_isdigit(c));
// }

/*
In most environments, it returns a non-zero value (usually 1,
but can be larger, like 2048), rather than just true or false.
This is because the C standard doesn't specify the exact value
to be returned when the function is true, only that the return value
must be non-zero if the condition is true.
*/
