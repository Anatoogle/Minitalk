/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:56:08 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:25 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_charcount(int n)
{
	int		i;
	int		minus;
	long	num;

	num = n;
	minus = 0;
	i = 1;
	if (num < 0)
	{
		minus = 1;
		num = num * (-1);
	}
	while (i <= 10 && num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i + minus);
}

char	*ft_itoa(int n)
{
	int		ln;
	long	num;
	char	*itoa;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ln = ft_num_charcount(n);
	itoa = (char *)malloc(ln + 1);
	if (!itoa)
		return (NULL);
	num = (long)n;
	if (n < 0)
		num = n * (-1);
	itoa[ln] = '\0';
	while (ln > 0)
	{
		itoa[ln - 1] = num % 10 + '0';
		num = num / 10;
		ln--;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}

// int	main(void)
// {
// 	// int i = -2147483648;
// 	int i = 0;
// 	// int i = 9;

// 	printf("%s\n", ft_itoa(i));
// 	// printf("%s", sft_itoa(i));
// }