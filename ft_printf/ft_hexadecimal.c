/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:00:07 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/04 10:01:05 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printhex(unsigned int ptr, int len, char *ftype)
{
	unsigned int	rem;
	unsigned int	num;
	char			*str;

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
		{
			if (ft_strcmp(ftype, "lower") == 0)
				num = rem - 10 + 'a';
			else if (ft_strcmp(ftype, "upper") == 0)
				num = rem - 10 + 'A';
		}
		ptr = ptr / 16;
		str[len - 1] = (char)num;
		len--;
	}
	return (str);
}

int	ft_puthex(unsigned int ptr, char *ftype)
{
	char	*str;
	int		len;

	len = ft_hexlen(ptr);
	if (ptr == 0)
	{
		len = len + ft_putstr("0");
		return (len);
	}
	str = ft_printhex(ptr, len, ftype);
	ft_putstr(str);
	free(str);
	return (len);
}

// void	ft_printhex(unsigned int  num, const char *format)
// {
// 	if (num >= 16)
// 	{
// 		ft_printhex(num / 16, format);
// 		ft_printhex(num % 16, format);
// 	}
// 	else
// 	{
// 		if (num <= 9)
// 			ft_putchar(num + '0');
// 		else
// 		{
// 			if (ft_strcmp(format, "lower") == 0)
// 				ft_putchar((num - 10 + 'a'));
// 			else if (ft_strcmp(format, "upper") == 0)
// 				ft_putchar((num - 10 + 'A'));
// 		}
// 	}
// }

// int	ft_puthex(unsigned int num, const char *format)
// {
// 	if (num == 0)
// 		return (write(1, "0", 1));
// 	else
// 	{
// 		// printf("### NUM:  %d\n", num);
// 		ft_printhex(num, format);
// 	}
// 	return (ft_hexlen(num));
// }
