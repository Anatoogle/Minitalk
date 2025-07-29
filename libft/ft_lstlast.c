/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:19:20 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/22 14:56:27 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tlast;

	tlast = (t_list *)lst;
	if (!lst)
		return (NULL);
	while (tlast)
	{
		if (!tlast->next)
			return (tlast);
		else
			tlast = tlast->next;
	}
	return (tlast);
}

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	*l3;
// 	t_list	*last;
// 	int		v1;
// 	int		v2;
// 	int		v3;

// 	v1 = 10;
// 	v2 = 20;
// 	v3 = 30;
// 	l1 = ft_lstnew(&v1);
// 	l2 = ft_lstnew(&v2);
// 	l3 = ft_lstnew(&v3);
// 	ft_lstadd_front(&l1, l2);
// 	ft_lstadd_front(&l1, l3);
// 	last = ft_lstlast(l1);
// 	if (last)
// 		printf("Last is %d\n\n", *(int *)last->content);
// 	while (l1)
// 	{
// 		printf("%d\n", *(int *)l1->content);
// 		l1 = l1->next;
// 	}
// }

/*
Parameters
	lst: The beginning of the list.
Return value
	Last node of the list
Description
	Returns the last node of the list.
*/