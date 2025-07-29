/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:02:36 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/25 10:34:48 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*lastn;
	t_list	*currentn;

	lastn = NULL;
	newlist = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		currentn = ft_lstnew(f(lst->content));
		if (!currentn)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		if (!newlist)
			newlist = currentn;
		else
			lastn->next = currentn;
		lastn = currentn;
		lst = lst->next;
	}
	return (newlist);
}

/*
...
if (!newl) newlist = currentn;
	this will be done once, so newlist will always point at the head of the list
else  lastn->next = currentn;
	lastn will always point to the last node in the new list
	we set lastn->next to currentn,
	effectively adding currentn as the next node after lastn.
lastn = currentn;
	this updates lastn to point to the new node currentn
	so that in the next iteration of the loop,
		we can add the next node to lastn.
lst = lst->next;
	set for the next iteration of the loop
*/

/*
Parameters
	lst:    The address of a pointer to a node.
	f:      The address of the function used to iterate on the list.
	del:    The address of the function used to delete the content of
			a node if needed.

Return value
	The new list.
	NULL if the allocation fails.

External functs.
	malloc, free

Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.
*/