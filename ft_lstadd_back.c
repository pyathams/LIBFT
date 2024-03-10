/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:11:04 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 16:32:20 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function name ft_lstadd_back
// Prototype void ft_lstadd_back(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the end of the list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tem;

	tem = *lst;
	if (!tem)
		*lst = new;
	else
	{
		while (tem -> next != NULL)
			tem = tem -> next;
		tem -> next = new;
	}
}

// // Function to create a new node
// t_list *create_node(void *content) {
//     t_list *new_node = (t_list *)malloc(sizeof(t_list));
//     if (new_node == NULL) {
//         return NULL; // Indicate failure to allocate memory
//     }
//     new_node->content = content;
//     new_node->next = NULL;
//     return new_node;
// }

// // Function to perform test cases
// int run_test_cases() {
//     // Test Case 1: Adding a node to an empty list
//     t_list *empty_list = NULL;
//     char *data1 = "Data1";
//     t_list *new_node_1 = create_node(data1);
//     if (new_node_1 == NULL) {
//         return 1; // Indicate failure
//     }
//     ft_lstadd_back(&empty_list, new_node_1);

//     // Test Case 2: Adding a node to a non-empty list
//     t_list *non_empty_list = create_node("Data2");
//     t_list *new_node_2 = create_node("Data3");
//     if (non_empty_list == NULL || new_node_2 == NULL) {
//         return 1; // Indicate failure
//     }
//     non_empty_list->next = new_node_2;
//     ft_lstadd_back(&non_empty_list, create_node("Data4"));

//     return 0; // Indicate success
// }

// int main() {
//     // Check if test cases run successfully
//     if (run_test_cases() == 0) {
//         printf("End\n"); // Indicate successful completion
//     } else {
//         fprintf(stderr, "Error occurred during test cases\n");
//     }
//     return 0;
// }