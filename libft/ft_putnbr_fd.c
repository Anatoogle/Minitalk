/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:01:13 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:37:16 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int n, int fd)
{
	if (n >= 10)
		ft_putnbr(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = n * (-1);
			write(fd, "-", 1);
		}
		ft_putnbr(n, fd);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(5, 1);
// }
