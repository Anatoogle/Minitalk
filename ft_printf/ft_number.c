/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:32:08 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/04 10:01:02 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = n * (-1);
		ft_putchar('-');
		count++;
	}
	if (n >= 10)
		count = count + ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (count + 1);
}
