/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:08:43 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 18:40:27 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	slen;

	slen = len;
	if (start >= ft_strlen(s))
	{
		dest = (char *)malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	if (len >= ft_strlen(s))
		slen = ft_strlen(s) - start;
	dest = (char *)malloc(slen + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// printf("slen: %zu\n", slen);
// printf("dest: %zu   j: %zu   slen: %zu", ft_strlen(dest), j, slen);
// if (len >= ft_strlen(s))
// 	slen = ft_strlen(s) - start;
// else
// 	slen = len;

// printf("%zu  %zu  %zu", ft_strlen(dest), j, slen);
// int	main(void)
// {
// 	printf("%s", ft_substr("01234", 2, 100));
// }

/*
(slen - start < len) ? (slen - start) : len;

	if (slen - start < len) is true, than "?" the solution is (slen - start)
	else ":" the solution is len

	if((slen - start) < len)    // if (slen - start) is smaller than len
		(slen - start)          // than (slen - start)
	else                        // else ( if (slen
			- start) is greater or to len)
		len                     // than (len)
*/

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*dest;
// 	size_t	i;
// 	size_t	j;
// 	size_t	slen;

// 	slen = len;
// 	if (start >= ft_strlen(s))
// 	{
// 		dest = (char *)malloc(1);
// 		dest[0] = '\0';
// 		return (dest);
// 	}
// 	if (len >= ft_strlen(s))
// 		slen = ft_strlen(s) - start;
// 	dest = (char *)malloc(slen + 1);
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			dest[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	dest[j] = '\0';
// 	return (dest);
// }