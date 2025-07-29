/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:07:56 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 12:36:11 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

// int main()
// {
// 	// printf("%s\n",ft_strchr(set, s1[start]));
// 	char s1[] = "Hallo";
// 	char s2[] = "Ho";

// 	printf("%s\n",ft_strtrim(s1, s2));
// }

/*
str = malloc(end - start + 2);

	String				" Hello "
	Trimmed Start		start = 2 (H)
	Trimmed End			end = 6 (o)
	Substring			"Hello"
	Length				end - start + 1 = 5
	Plus Null Term		+1 (for \0)
	Total				end - start + 2 = 6

end = ft_strlen(s1) - 1;
	get the index of the last character

while	(ft_strchr(set, s1[start]) && start <= end)
	start++;

	for every occurence, do start++

start <= end

*/