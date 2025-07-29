/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:01:30 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 15:23:37 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)malloc(ft_strlen(s) + 1);
	if (d == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// int	main(void)
// {
// 	char	src[] = "Hallo";
// 	char	*dst;

// 	dst = ft_strdup(src);
// 	printf("%p\n", &src);
// 	printf("%p\n", &dst);
// 	printf("%s\n", src);
// 	printf("%s", dst);
// }
