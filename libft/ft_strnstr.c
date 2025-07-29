/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:26:55 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 16:07:38 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = 0;
	if (*little == '\0' || !little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == '\0' && i + j < len)
			{
				c = (char *)big + i;
				return (c);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*largestring = "Foo Bar Baz";
// 	const char	*smallstring = "";
// 	char		*ptr;

// 	ptr = ft_strnstr(largestring, smallstring, 7);
// 	printf("%s", ptr);
// }
