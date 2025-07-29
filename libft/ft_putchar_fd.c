/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:52 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 14:08:20 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('c', 1);
// }

/*
The ft_putchar_fd function writes a single character to a file descriptor.

char c:
	The character to write.
int fd:
	The file descriptor to write to.

	0: Standard input.
		Typically used for reading input from the keyboard or input redirection.
		Writing to fd = 0 is unusual and might lead to unexpected behavior.
	1: Standard output.
		Used for writing output to the console or terminal.
	2: Standard error.
		Used for writing error messages or diagnostics to the console.

	Other values are for files or devices opened during the program.

write(fd, &c, 1);
	1
		Number of bytes to write (a single character).
*/