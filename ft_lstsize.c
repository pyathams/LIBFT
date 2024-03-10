/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:08:12 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 15:37:39 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function name ft_lstsize
// Prototype int ft_lstsize(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value The length of the list
// External functs. None
// Description Counts the number of nodes in a list.

int	ft_lstsize(t_list *lst)
{
	t_list	*tem;
	int		count;

	if (!lst)
		return (0);
	tem = lst;
	count = 0;
	while (tem != NULL)
	{
		count++;
		tem = tem -> next;
	}
	return (count);
}

// int run_tests() {
//     // Create test cases
//     t_list *list1 = malloc(sizeof(t_list));
//     t_list *list2 = malloc(sizeof(t_list));
//     t_list *list3 = malloc(sizeof(t_list));

//     list1->next = list2;
//     list2->next = list3;
//     list3->next = NULL;

//     int size1 = ft_lstsize(list1); // Expected: 3

//     // Free memory
//     free(list1);
//     free(list2);
//     free(list3);

//     // Check test results
//     if (size1 != 3) {
//         return 0; // Test case failed
//     }

//     return 1; // All tests passed
// }

// int main() {
//     // Run test cases
//     if (run_tests()) {
//         // If all tests are successful, print "end"
//         printf("end\n");
//     } else {
//         // If there are errors in test cases, print error message
//         printf("There are errors in test cases.\n");
//     }

//     return 0;
// }