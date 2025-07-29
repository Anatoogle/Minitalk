/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:02:57 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 16:51:15 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (count);
		count++;
		i++;
	}
	return (count);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == (char)c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != (char)c && s[i] != '\0')
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		wlen;
	int		index;

	dest = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !dest)
		return (0);
	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		while (s[i] == (char)c)
			i++;
		if (s[i] != '\0')
		{
			wlen = ft_wordlen(s + i, c);
			dest[index] = ft_substr(s + i, 0, wlen);
			i = i + wlen;
			index++;
		}
	}
	dest[index] = NULL;
	return (dest);
}

// int	main(void)
// {
// 	char	s1[] = "    qweaaaa123  aaSaa456  aaaaeqw";
// 	int		i;
// 	char	**sar;

// 	i = 0;
// 	sar = ft_split(s1, 'a');
// 	while (sar[i])
// 	{
// 		printf("%s\n", sar[i]);
// 		free(sar[i]);
// 		i++;
// 	}
// 	free(sar);
// }

/*
(char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));

(char **)
	allocating memory for an array of strings (an array of char *)

sizeof(char *)
	gives the size needed to store a pointer to char,
	which is typically 8 bytes on a 64-bit system and 4 bytes on a 32-bit system.

if one String is "hello"
	| h | e | l | l | o | \0 |

Array of Strings split "hello world" by its Space
	| ptr_to_hello | ptr_to_world | NULL |
	It allocates 3 pointers (2 + 1 for the NULL),
	and each pointer requires sizeof(char *) bytes
*/