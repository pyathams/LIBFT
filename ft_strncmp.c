/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:11:10 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/07 00:21:10 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
/*
DESCRIPTION
       The  strcmp()  function  compares the two strings s1 and s2.
       The locale is not taken into  account  (for  a  locale-aware
       comparison,  see  strcoll(3)).  The comparison is done using
       unsigned characters.

       strcmp() returns an integer indicating  the  result  of  the
       comparison, as follows:

       • 0, if the s1 and s2 are equal;

       • a negative value if s1 is less than s2;

       • a positive value if s1 is greater than s2.

       The  strncmp()  function is similar, except it compares only
       the first (at most) n bytes of s1 and s2.

RETURN VALUE
       The strcmp() and strncmp() functions return an integer  less
       than,  equal  to, or greater than zero if s1 (or the first n
       bytes thereof) is found, respectively, to be less  than,  to
       match, or be greater than s2.

*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char )s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	const char *str1_empty = "";
//     const char *str2_empty = "";
//     int result = strncmp(str1_empty, str2_empty, 5);
// 	int result1 = ft_strncmp(str1_empty, str2_empty, 5);
//     printf("Test case 1: Empty strings: %d\n", result);
// 	printf("Test case 1: Empty strings: %d\n", result1);

//     // Test case 2: Equal strings
//     const char *str1_equal = "test\200";
//     const char *str2_equal = "test\0";
//     result = strncmp(str1_equal, str2_equal, 6);
// 	result1 = ft_strncmp(str1_equal, str2_equal, 6);
//     printf("Test case 2: Equal strings: %d\n", result);
// 	printf("Test case 2: Equal strings: %d\n", result1);

//     // Test case 3: Different strings
//     const char *str1_diff = "hello";
//     const char *str2_diff = "world";
//     result = strncmp(str1_diff, str2_diff, 5);
// 	result1 = ft_strncmp(str1_diff, str2_diff, 5);
//     printf("Test case 3: Different strings: %d\n", result);
// 	printf("Test case 3: Different strings: %d\n", result1);
// }
