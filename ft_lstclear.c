/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:13:59 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 19:06:22 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function name ft_lstclear
// Prototype void ft_lstclear(t_list **lst, void (*del)(void
// *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// del: The address of the function used to delete
// the content of the node.
// Return value None
// External functs. free
// Description Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	current = *lst;
	while (current != NULL && del)
	{
		next_node = current -> next;
		del(current -> content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}

// // Sample delete function
// void delete_function(void *content) {
//     free(content);
// }

// int main() {
//     // Test Case 1: Empty list
//     t_list *empty_list = NULL;
//     ft_lstclear(&empty_list, &delete_function);
//     if (empty_list == NULL) {
//         printf("Test Case 1 passed: Empty list cleared successfully.\n");
//     } else {
//         printf("Test Case 1 failed: Empty list not cleared.\n");
//     }

//     // Test Case 2: List with one node
//     t_list *list_with_one_node = malloc(sizeof(t_list));
//     list_with_one_node->content = malloc(sizeof(int));
//     *(int *)(list_with_one_node->content) = 10;
//     list_with_one_node->next = NULL;
//     ft_lstclear(&list_with_one_node, &delete_function);
//   if (list_with_one_node == NULL) {
//    printf("Test Case2passed:Listwithonenodeclearedsuccessfully.\n");
//     } else {
//         printf("Test Case 2 failed: List with one node not cleared.\n");
//     }

//     // Test Case 3: List with multiple nodes
//     t_list *list_with_multiple_nodes = malloc(sizeof(t_list));
//     list_with_multiple_nodes->content = malloc(sizeof(int));
//     *(int *)(list_with_multiple_nodes->content) = 20;
//     list_with_multiple_nodes->next = malloc(sizeof(t_list));
//     list_with_multiple_nodes->next->content = malloc(sizeof(int));
//     *(int *)(list_with_multiple_nodes->next->content) = 30;
//     list_with_multiple_nodes->next->next = NULL;
//     ft_lstclear(&list_with_multiple_nodes, &delete_function);
//if (list_with_multiple_nodes == NULL) {
//  printf("Test Case 3 passed:Listwithmultiple nodes cleared successfully.\n");
//}else {
//printf("Test Case 3 failed: List with multiple nodes not cleared.\n");
//}

//     return 0;
// }