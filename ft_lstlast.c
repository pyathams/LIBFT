/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:42:34 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 15:50:44 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function name ft_lstlast
// Prototype t_list *ft_lstlast(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value Last node of the list
// External functs. None
// Description Returns the last node of the list.

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tem;

	if (!lst)
		return (NULL);
	tem = lst;
	while (tem -> next)
		tem = tem -> next;
	return (tem);
}

// int main() {
//     // Test case 1: Empty list
//     t_list *empty_list = NULL;
//     if (ft_lstlast(empty_list) == NULL) {
//         printf("Test case 1 passed!\n");
//     } else {
//         printf("Test case 1 failed!\n");
//         return 1; // exit with error
//     }

//     // Test case 2: List with single node
//     int data = 10;
//     t_list *single_node_list = ft_lstnew(&data);
//     if (ft_lstlast(single_node_list) == single_node_list) {
//         printf("Test case 2 passed!\n");
//     } else {
//         printf("Test case 2 failed!\n");
//         return 1; // exit with error
//     }

//     // Test case 3: List with multiple nodes
//     int data2 = 20;
//     int data3 = 30;
//     t_list *list_with_multiple_nodes = ft_lstnew(&data);
//     list_with_multiple_nodes->next = ft_lstnew(&data2);
//     list_with_multiple_nodes->next->next = ft_lstnew(&data3);
//     if (ft_lstlast(list_with_multiple_nodes)->content == &data3) {
//         printf("Test case 3 passed!\n");
//     } else {
//         printf("Test case 3 failed!\n");
//         return 1; // exit with error
//     }

//     printf("All tests passed!\n");
//     return 0; // exit successfully
// }