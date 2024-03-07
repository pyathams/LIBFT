/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:43 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/03 22:59:40 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>
/*
DESCRIPTION
       The memchr() function scans the initial n bytes  of  the
       memory area pointed to by s for the first instance of c.
       Both c and the bytes of the memory area pointed to by  s
       are interpreted as unsigned char.

       The  memrchr()  function  is like the memchr() function,
       except that it searches backward from the end of  the  n
       bytes pointed to by s instead of forward from the begin‐
       ning.

       The rawmemchr() function is similar to memchr(): it  as‐
       sumes  (i.e.,  the programmer knows for certain) that an
       instance of c lies somewhere in the memory area starting
       at  the location pointed to by s, and so performs an op‐
       timized search for c (i.e., no use of a  count  argument
       to  limit the range of the search).  If an instance of c
       is not found, the results are unpredictable.   The  fol‐
       lowing  call is a fast means of locating a string's ter‐
       minating null byte:

           char *p = rawmemchr(s, '\0');

RETURN VALUE
       The memchr() and memrchr() functions return a pointer to
       the  matching byte or NULL if the character does not oc‐
       cur in the given memory area.

       The rawmemchr() function returns a pointer to the match‐
       ing  byte,  if  one  is  found.   If no matching byte is
       found, the result is unspecified.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*(const unsigned char *)s == (unsigned char)(c))
			return ((void *)s);
		s++;
	}
	return (NULL);
}
/*
int	main(void)
{
    char str[] = "Hello, World!";
    char *result;
    const char *expected;

    // Test case 1: Search for character 'o' in the string
    result = memchr(str, 'o', strlen(str));
    expected = "o, World!";
    printf("Test case 1: Search for 'o'\n");
    printf("Expected: '%s'\n", expected);
    printf("Result: '%s'\n", result);
    printf("Test result: %s\n\n", strcmp(result, expected) == 0 
	? "Passed" : "Failed");

    // Test case 2: Search for character 'x' which is not in the string
    result = memchr(str, 'x', strlen(str));
    expected = NULL;
    printf("Test case 2: Search for 'x'\n");
    printf("Expected: NULL\n");
    printf("Result: %p\n", result);
    printf("Test result: %s\n\n", result == expected ? "Passed" : "Failed");

    // Test case 3: Search for character 'H' in the string
    result = memchr(str, 'H', strlen(str));
    expected = str;
    printf("Test case 3: Search for 'H'\n");
    printf("Expected: '%s'\n", expected);
    printf("Result: '%s'\n", result);
    printf("Test result: %s\n\n", result == expected ? "Passed" : "Failed");

    return 0;
}*/
