/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:44:57 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 14:12:38 by pyathams         ###   ########.fr       */
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
// Function name ft_lstadd_front
// Prototype void ft_lstadd_front(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the beginning of the list.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

// // Define your test cases here
// void test_cases() {
//     // Test case 1: Empty list, new node
//     t_list *lst1 = NULL;
//     t_list *new1 = malloc(sizeof(t_list));
//     new1->content = "Node 1";
//     new1->next = NULL;
//     ft_lstadd_front(&lst1, new1);

//     // Test case 2: Non-empty list, new node
//     t_list *lst2 = malloc(sizeof(t_list));
//     lst2->content = "Existing Node";
//     lst2->next = NULL;
//     t_list *new2 = malloc(sizeof(t_list));
//     new2->content = "New Node";
//     new2->next = NULL;
//     ft_lstadd_front(&lst2, new2);

//     // Additional test cases can be added here
// }

// int main() {
//     // Call test_cases function to run the test cases
//     test_cases();
// 	printf("end\n");
//     return 0;
// }