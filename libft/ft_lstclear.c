/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:43 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/22 16:54:57 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char		*ft_strdup(const char *s);
// static char		*ft_strdup(const char *s);
// static void		del(void *content);
// t_list			*ft_lstnew(void *content);
// void			ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;

// 	str1 = ft_strdup("Hello");
// 	str2 = ft_strdup("World");
// 	str3 = ft_strdup("Nice");
// 	lst1 = ft_lstnew(str1);
// 	lst2 = ft_lstnew(str2);
// 	lst3 = ft_lstnew(str3);
// 	ft_lstadd_front(&lst1, lst2);
// 	ft_lstadd_front(&lst1, lst3);
// 	if (lst1)
// 	{
// 		printf("t_list content:\n");
// 		while (lst1)
// 		{
// 			printf("%s\n", (char *)lst1->content);
// 			lst1 = lst1->next;
// 		}
// 	}
// 	if (lst1)
// 	{
// 		printf("t_list content:");
// 		while (lst1)
// 		{
// 			printf("%s\n", (char *)lst1->content);
// 			lst1 = lst1->next;
// 		}
// 	}
// 	else
// 		printf("t_list content empty");
// 	ft_lstclear(&lst1, del);
// }

// // Function to delete the content of the node (in this case, free the string)
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
In the function

t_list *lst
	For functions like ft_lstsize that just read and traverse the list,
	t_list *lst is enough.

t_list **lst
	For functions that modify the lists structure, such as adding or removing
	nodes, you need t_list **lst so you can change the head of the list
*/

/*
Parameters
	lst: The address of a pointer to a node.
	del: The address of the function used to delete
	the content of the node.
External functs.
	free
Description
	Deletes and frees the given node and every successor
	of that node, using the function ’del’ and free(3).
	Finally, the pointer to the list must be set to NULL.
*/