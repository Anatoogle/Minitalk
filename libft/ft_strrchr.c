/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:42 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 14:01:59 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sdest;
	int		i;

	sdest = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			sdest = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		sdest = (char *)s + i;
	return (sdest);
}

// int	main(void)
// {
//     printf("%s", ft_strrchr("Hallodgdvlpo", 'l'));
// }
