/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:22:03 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 13:42:44 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <ctype.h>
// #include <stdio.h>
// #include <bsd/string.h>
// #include <assert.h>
// #include "libft.h"
// #include <ctype.h>
// #include <stdio.h>
// #include <bsd/string.h>
// #include <assert.h>
//
// Function name ft_lstnew
// Prototype t_list *ft_lstnew(void *content);
// Turn in files -
// Parameters content: The content to create the node with.
// Return value The new node
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew -> content = content;
	lstnew -> next = NULL;
	return (lstnew);
}

// void test_lstnew() {
//     t_list *list = ft_lstnew("test");
//     assert(list != NULL);
//     assert(list->content != NULL);
//     assert(list->next == NULL);
//     assert(strcmp(list->content, "test") == 0);
//     free(list);
// }
//
// int	main()
// {
// 	test_lstnew();
// 	printf("End");
// }