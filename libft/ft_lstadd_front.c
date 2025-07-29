/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:56:13 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 17:18:27 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 	int		v1;
// 	int		v2;
// 	int		v3;

// 	v1 = 10;
// 	v2 = 20;
// 	v3 = 30;
// 	lst1 = ft_lstnew(&v1);
// 	lst2 = ft_lstnew(&v2);
// 	lst3 = ft_lstnew(&v3);

// 	printf("%d\n", *(int *)lst1->content);
// 	if (lst1->next)
// 		printf("%d\n", *(int *)lst1->next->content);
// 	else
// 		printf("No Content\n\n");

// 	ft_lstadd_front(&lst1, lst2);
// 	ft_lstadd_front(&lst1, lst3);

// 	printf("%d\n", *(int *)lst1->content);
//     if (lst1->next)
// 		printf("%d\n\n", *(int *)lst1->next->content);
// 	else
// 		printf("No Content\n\n");

// 	while (lst1)
// 	{
// 		printf("%d\n", *(int *)lst1->content);
// 		lst1 = lst1->next;
// 	}
// }

/*
Adds the node ’new’ at the beginning of the list.


lst:
	The address of a pointer to the first link of a list.
new:
	The address of a pointer to the node to be added to the list.
*/