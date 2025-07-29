/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:57:16 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:29 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	c;

// 	c = 0;
// 	while (c <= 127)
// 	{
// 		printf("%d  %d\n", c, isascii(c));
// 		printf("%d  %d\n\n", c, ft_isascii(c));
// 		c++;
// 	}
// }
