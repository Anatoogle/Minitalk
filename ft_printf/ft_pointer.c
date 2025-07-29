/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:29:02 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/04 10:09:18 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlen(size_t num)
{
	size_t	i;

	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	ft_putptr(size_t ptr)
{
	char	*str;
	int		len;

	len = ft_hexlen(ptr);
	if (ptr == 0)
	{
		len = len + ft_putstr("(nil)");
		return (len);
	}
	str = ft_strptr(ptr, len);
	ft_putstr("0x");
	len = len + 2;
	ft_putstr(str);
	free(str);
	return (len);
}

char	*ft_strptr(size_t ptr, int len)
{
	size_t	rem;
	size_t	num;
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (ptr != 0)
	{
		rem = ptr % 16;
		if (rem < 10)
			num = rem + 48;
		else
			num = rem - 10 + 'a';
		ptr = ptr / 16;
		str[len - 1] = (char)num;
		len--;
	}
	return (str);
}
