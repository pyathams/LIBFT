/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:10:37 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 19:27:11 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function name ft_lstiter
// Prototype void ft_lstiter(t_list *lst, void (*f)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// Return value None
// External functs. None
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst && !f)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// void    print_content(void *content)
// {
//     printf("%s\n", (char *)content);
// }

// void    test_ft_lstiter()
// {
//     // Test case 1: Empty list
//     printf("Test case 1:\n");
//     ft_lstiter(NULL, print_content);

//     // Test case 2: List with some elements
//     printf("\nTest case 2:\n");
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));
//     node1->content = "Node 1";
//     node1->next = node2;
//     node2->content = "Node 2";
//     node2->next = node3;
//     node3->content = "Node 3";
//     node3->next = NULL;

//  ft_lstiter(node1, print_content); // Call ft_lstiter with non-empty list
//     // Free allocated memory
//     free(node1);
//     free(node2);
//     free(node3);
// }

// int main()
// {
//     test_ft_lstiter(); // Call test function
//     printf("end\n"); // Print "end" if all tests passed successfully
//     return 0;
// }