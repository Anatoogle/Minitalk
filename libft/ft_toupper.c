/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:26:09 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 12:09:39 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

// #include <unistd.h>

// int	main(void)
// {
// 	char	c;
//     char	d;

// 	c = 'a';
// 	write(1, &c, 1);
//     d = toupper(c);
// 	c = ft_toupper(c);
// 	write(1, &c, 1);
//     write(1, &d, 1);
// }
