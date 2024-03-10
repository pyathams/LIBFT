/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:20:30 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/09 18:23:18 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>
/*
Function name ft_itoa
Prototype char *ft_itoa(int n);
Turn in files -
Parameters n: the integer to convert.
Return value The string representing the integer.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

static size_t	ft_count(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_returnstr(char *str, int n, size_t len)
{
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len > 0 && n != 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (ft_returnstr(str, n, len));
}

// char *ft_itoa(int n);

// void test_ft_itoa(int n, char *expected_result) {
//     char *result = ft_itoa(n);
//     if (result == NULL) {
//         printf("Test failed: Input: %d, Expected: \"%s\",
//Result: NULL\n", n, expected_result);
//         return;
//     }
//     if (strcmp(result, expected_result) == 0) {
//         printf("Test passed: Input: %d, Expected: \"%s\",
//Result: \"%s\"\n", n, expected_result, result);
//     } else {
//         printf("Test failed: Input: %d, Expected: \"%s\",
//Result: \"%s\"\n", n, expected_result, result);
//     }
//     free(result); // Free allocated memory
// }

// int main() {
//     printf("Running unit tests for ft_itoa function\n\n");

//     // Test cases
//     test_ft_itoa(0, "0");
//     test_ft_itoa(123, "123");
//     test_ft_itoa(-456, "-456");
//     test_ft_itoa(2147483647, "2147483647");
//     test_ft_itoa(-2147483648, "-2147483648");
//     // Add more test cases here if needed

//     return 0;
// }