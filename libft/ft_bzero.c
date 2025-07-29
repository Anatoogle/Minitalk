/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:33:39 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:55:21 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*value;
	size_t			i;

	i = 0;
	value = (unsigned char *)s;
	while (i < n)
	{
		value[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	str[10] = "HalloHello";
// 	int		i;

// 	printf("%s\n", str);
// 	// bzero(str, 9);
// 	ft_bzero(str, 8);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%c\n", str[i]);
// 		i++;
// 	}
// }
