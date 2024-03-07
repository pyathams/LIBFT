/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:20:12 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/06 20:36:49 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
Function name ft_strmapi
Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
Turn in files -
Parameters s: The string on which to iterate.
f: The function to apply to each character.
Return value The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.
External functs. malloc
Description Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Prototype of ft_strmapi function
// char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

// // Mapping function that converts lowercase letters to uppercase
// char uppercase_mapping(unsigned int index, char c) {
//     (void)index; // Silence unused parameter warning
//     if (c >= 'a' && c <= 'z') {
//         return c - ('a' - 'A'); // Convert lowercase to uppercase
//     } else {
//         return c; // Return unchanged if not lowercase
//     }
// }

// // Unit test function
// void unit_test(char const *input,
// char (*mapping_function)(unsigned int, char), char const *expected_output) {
//     char *result = ft_strmapi(input, mapping_function);

//     if (!result && !expected_output) {
//         printf("Test Passed: NULL input and expected output\n");
//     } else if (!strcmp(result, expected_output)) {
//         printf("Test Passed: Input: \"%s\",
// Expected: \"%s\", Result: \"%s\"\n", input, expected_output, result);
//     } else {
//         printf("Test Failed: Input: \"%s\", 
//Expected: \"%s\", Result: \"%s\"\n", input, expected_output, result);
//     }

//     // Free dynamically allocated memory
//     free(result);
// }

// int main() {
// Test case 1: Simple mapping function that converts lowercase to uppercase
//     unit_test("hello", uppercase_mapping, "HELLO");

//     // Test case 2: NULL input for both string and function pointer
//     unit_test(NULL, NULL, NULL);

//test case 3: Custom mapping function that adds 1 to 
//the ASCII value of each character
//     char expected_output[] = "ifmmp";
//     char increment_mapping(unsigned int index, char c) {
//         (void)index; // Silence unused parameter warning
//         return c + 1;
//     }
//     unit_test("hello", increment_mapping, expected_output);

//     return 0;
// }