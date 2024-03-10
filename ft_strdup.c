/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:29:15 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/10 18:52:21 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
/*
DESCRIPTION
       The strdup() function returns a  pointer  to  a  new  string
       which  is  a  duplicate of the string s.  Memory for the new
       string is obtained with malloc(3), and  can  be  freed  with
       free(3).

       The  strndup()  function  is  similar,  but copies at most n
       bytes.  If s is longer than n, only n bytes are copied,  and
       a terminating null byte ('\0') is added.

       strdupa()  and  strndupa() are similar, but use alloca(3) to
       allocate the buffer.  They are available only when using the
       GNU  GCC  suite,  and  suffer  from the same limitations de‐
       scribed in alloca(3).

RETURN VALUE
       On success, the strdup() function returns a pointer  to  the
       duplicated  string.   It returns NULL if insufficient memory
       was available, with errno set to indicate the cause  of  the
       error.

*/

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
	{
		return (NULL);
	}
	ft_strlcpy(dup, s, (ft_strlen(s) + 1));
	return (dup);
}

// void test_case(const char *input_string) {
//     char *duplicate = ft_strdup(input_string);
//     if (duplicate) {
//         printf("Original String: \"%s\"\n", input_string);
//         printf("Duplicated String: \"%s\"\n", duplicate);
//         free(duplicate); // Free memory allocated by ft_strdup
//     } else {
//         printf("Memory allocation failed for input string: \"%s\"\n", 
//input_string);
//     }
// }

// int main() {
//     // Test cases
//     test_case("Hello, world!");
//     test_case("1234567890");
//     test_case("");
//     test_case("This is a test string.");
//     test_case("abcdefghijklmnopqrstuvwxyz");
//     return 0;
// }