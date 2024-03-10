/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:45:46 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 18:13:27 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function name ft_lstdelone
// Prototype void ft_lstdelone(t_list *lst, void (*del)(void
// *));
// Turn in files -
// Parameters lst: The node to free.
// del: The address of the function used to delete
// the content.
// Return value None
// External functs. free
// Description Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst -> content);
		free(lst);
	}
}

// // Your delete function
// void my_delete_function(void *content) {
//     free(content);
// }

// // Test case 1: Valid input with content
// void test_valid_input_with_content() {
//     t_list *node = (t_list *)malloc(sizeof(t_list));
//     if (node == NULL) {
//         // Handle memory allocation failure
//         return;
//     }
//     node->content = malloc(sizeof(int)); // Allocating memory for content
//     *(int *)(node->content) = 5; // Storing some value in content

//     // Passing valid input to the function
//     ft_lstdelone(node, &my_delete_function);
// }

// // Test case 2: Valid input with NULL content
// void test_valid_input_with_null_content() {
//     t_list *node = (t_list *)malloc(sizeof(t_list));
//     if (node == NULL) {
//         // Handle memory allocation failure
//         return;
//     }
//     node->content = NULL; // Content is NULL

//     // Passing valid input to the function
//ft_lstdelone(node, &my_delete_function);
// }

// // Test case 3: NULL list node
// void test_null_node() {
//     // Passing NULL node to the function
//ft_lstdelone(NULL, &my_delete_function);
// }

// int main() {
//     // Run test cases
//     test_valid_input_with_content();
//     test_valid_input_with_null_content();
//     test_null_node();

//     printf("End\n"); // Indicate that all tests have been completed
//     return 0;
// }