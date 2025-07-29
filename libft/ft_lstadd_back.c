/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:22:19 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/26 10:37:03 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// int		ft_lstsize(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}

// int	main(void)
// {
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 	t_list	*lst4;
// 	int		v1;
// 	int		v2;
// 	int		v3;
// 	int		v4;

// 	v1 = 10;
// 	v2 = 20;
// 	v3 = 30;
// 	v4 = 40;
// 	lst1 = ft_lstnew(&v1);
// 	lst2 = ft_lstnew(&v2);
// 	lst3 = ft_lstnew(&v3);
// 	lst4 = ft_lstnew(&v4);
// 	ft_lstadd_front(&lst1, lst2);
// 	ft_lstadd_front(&lst1, lst3);
// 	ft_lstadd_back(&lst1, lst4);
// 	while (lst1)
// 	{
// 		printf("%d\n", *(int *)lst1->content);
// 		lst1 = lst1->next;
// 	}
// }

/*
Parameters
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be
	added to the list.
Description
	Adds the node ’new’ at the end of the list.
*/

/*
t_list **lst:
	This is a pointer to the pointer of the head of the list.
	It's a double pointer because the function needs to modify 
	the original list.
if (lst)
	checks if lst (the pointer to the list) is not NULL
	This prevents dereferencing a NULL pointer, which would cause a crash.
if (!*lst)  *lst = new;
	If the list is empty (*lst is NULL),
	then it sets the head of the list (*lst) to point to the new node (new).
	Essentially, the list was empty, and now the new node is the first element.
else { tmp = ft_lstlast(*lst);
	If the list is not empty,
	it needs to find the last element in the list to append the new node 
	to the end.
tmp->next = new;
	Once the last node (tmp) is found,
		it sets tmp->next to point to the new node,
	effectively adding the new node to the end of the list.
*/