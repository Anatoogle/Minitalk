/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:13:00 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:12 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char		*ft_strdup(const char *s);
// static char		*ft_strdup(const char *s);
// static void		del(void *content);
// t_list			*ft_lstnew(void *content);

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	char	*str;
// 	t_list	*lst;

// 	str = ft_strdup("Hallo");
// 	printf("String created:      %s\n", (char *)str);
// 	lst = ft_lstnew(str);
// 	printf("t_list content:      %s\n", (char *)lst->content);
// 	ft_lstdelone(lst, del);
// 	printf("String del and free: %s\n", str);
// 	// printf("t_list: %s\n", lst->content);
// }

// // Function to delete the content of the node (in this case, 
// // free the string)
// static void	del(void *content)
// {
// 	free(content); // Free the content (string in this case)
// }

// static size_t	ft_strlen(const char *s)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		s++;
// 		count++;
// 	}
// 	return (count);
// }

// static char	*ft_strdup(const char *s)
// {
// 	size_t	i;
// 	char	*d;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	d = (char *)malloc(ft_strlen(s) + 1);
// 	if (d == NULL)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	d[i] = '\0';
// 	return (d);
// }

/*
first have to call del function before free the memory

after free, you cant access lst anymore this is unsafe to use del afterwards

thoose 2 functions are functionally the same
	(*del)(lst->content);
	del(lst->content);

Why NOT "free(lst->content);"
	if lst->content points to dynamically allocated memory and want to free
	that memory, you still need to free the node itself
	"free(lst);" free the memory for the node lst which contains the content 
    pointer	and opotentially other fields like a next pointer
*/

/*
Parameters
	lst: The node to free.
	del: The address of the function used to delete the content.
External functs.
	free
Description
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.
*/
