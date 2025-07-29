/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:54:36 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/22 12:46:46 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (t_list *)lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	int		v1;
// 	int		v2;

// 	v1 = 10;
// 	v2 = 20;
// 	l1 = ft_lstnew(&v1);
// 	l2 = ft_lstnew(&v2);
// 	ft_lstadd_front(&l1, l2);
// 	printf("%d", ft_lstsize(l1));
// }

/*
Parameters
	lst: The beginning of the list.
Return value
	The length of the list
Description
	Counts the number of nodes in a list.

tmp = (t_list *)lst;
	tmp is used for traversal (tmp = tmp->next;)
	it preserve the original lst, because you are not modifying lst
	you're using a separate pointer (tmp) to traverse the list.
*/
