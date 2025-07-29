/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:42:24 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/21 17:10:05 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// // EXAMPLE 1
// int	main(void)
// {
// 	int		value;
// 	t_list		 *node;

// 	value = 42;
// 	node = ft_lstnew(&value);
// 	if (node)
// 		printf("content: %d\n", *(int *)node->content);
// 	else
// 		printf("failed\n");
// }

// // EXAMPLE 2
// int	main(void)
// {
//     char		value[] = "hallo";
// 	t_list		 *node;

// 	node = ft_lstnew(&value);
// 	if (node)
// 		printf("content: %s\n", (char *)node->content);
// 	else
// 		printf("failed\n");
// }

/*
- the function returns a pointer to a t_list(a linked list node)
- the function takes a single argument content of type void * (any type of data)
- create variable newnode and allocate memory (t_list *)malloc(sizeof(t_list));
	- (t_list *)
		- is a cast, converyting malloc return value into a t_list
	- sizeof(t_list)
		- large enough to hold a t_list structure
	- this memory will be used to store the content of the node and the pointer
		to the next node(next)
- newnode->content = content;
	- content argument passed to the function is assigned to the content field
		of the new node
- newnode->next = NULL;
	- The next pointer is set to NULL
		indicating that this node is currently the last node in the list


Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’.
The variable ’next’ is initialized to NULL.

*/
