/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:56 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 14:09:10 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*d;
	size_t	ls;

	if (!s || !f)
		return (NULL);
	ls = ft_strlen(s);
	d = (char *)malloc(ls + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}

// static char	ft_test(unsigned int i, char c)
// {
// 	return (c + i + 1);
// }

// int main()
// {
//     char *test = ft_strmapi("123", ft_test);

//     if(test)
//         printf("%s\n", test);
// }

/*
Parameters
s:
	The string on which to iterate.
f:
	The function to apply to each character.

Return value
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.

External functs.
	malloc

Description
	Applies the function f to each character of the
	string s, passing its index as the first argument
	and the character itself as the second. A new
	string is created (using malloc(3)) to collect



The function returns a pointer to a dynamically allocated string.

ft_strmapi is a flexible tool for transforming a string by applying a
custom function to each character, with access to both the character and
its index. This allows complex transformations that depend not just on
the character itself but also on its position in the string.


EXPLAINATION:

result[i] = (*f)(i, s[i]);
	Iterate through each character in the input string s using the index i:

(*f)(i, s[i]):

(*f)
	is a function pointer dereferenced to call the function it points to.

(i, s[i])
	means the function f is being called with two arguments

result[i]
	Store the result of f


EXAMPLE:
char	my_func(unsigned int i, char c) {
	return (c + i);

ft_strmapi("hello", my_func());
}
*/