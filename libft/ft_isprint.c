/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:03:38 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:27 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
// 		printf("%d  %d\n", c, isprint(c));
// 		printf("%d  %d\n\n", c, ft_isprint(c));
// 		c++;
// 	}
// }
