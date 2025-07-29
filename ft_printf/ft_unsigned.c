/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:31:21 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/04 10:03:54 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignednbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i = ft_putunsignednbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (i + 1);
}
