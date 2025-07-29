/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:05:14 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 13:02:21 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// static void ft_test(unsigned int i, char *c)
// {
//     *c = *c + i;
// }

// int main()
// {
//     char test[] = "12345";
//     ft_striteri(test, ft_test);

//     printf("%s\n", test);
// }

/*
char test[]
	when you need a modifiable local copy of the string.
char *test
	when you want to work with a read-only string literal
	or if you plan to reassign the pointer.

*/