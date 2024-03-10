/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:08:10 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/09 18:07:34 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>
/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings re‐
     spectively.  They are designed to be safer, more consistent, and less er‐
     ror prone replacements for strncpy(3) and strncat(3).  Unlike those func‐
     tions, strlcpy() and strlcat() take the full size of the buffer (not just
     the length) and guarantee to NUL-terminate the result (as long as size is
     larger than 0 or, in the case of strlcat(), as long as there is at least
     one byte free in dst).  Note that a byte for the NUL should be included
     in size.  Also note that strlcpy() and strlcat() only operate on true “C”
     strings.  This means that for strlcpy() src must be NUL-terminated and
     for strlcat() both src and dst must be NUL-terminated.

     The strlcpy() function copies up to size - 1 characters from the NUL-ter‐
     minated string src to dst, NUL-terminating the result.

     The strlcat() function appends the NUL-terminated string src to the end
     of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
     nating the result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the
     string they tried to create.  For strlcpy() that means the length of src.
     For strlcat() that means the initial length of dst plus the length of
     src.  While this may seem somewhat confusing, it was done to make trunca‐
     tion detection simple.

     Note, however, that if strlcat() traverses size characters without find‐
     ing a NUL, the length of the string is considered to be size and the des‐
     tination string will not be NUL-terminated (since there was no space for
     the NUL).  This keeps strlcat() from running off the end of a string.  In
     practice this should not happen (as it means that either size is incor‐
     rect or that dst is not a proper “C” string).  The check exists to pre‐
     vent potential security problems in incorrect code.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (dest[i] && i < dstsize)
	{
		i++;
	}
	ret = ft_strlcpy(dest + i, src, (dstsize - i));
	return (ret + i);
}

// void test_functions(char *dest, const char *src, size_t dstsize) {
//     char dest_ft[20], dest_str[20];
//     strcpy(dest_ft, dest);
//     strcpy(dest_str, dest);

//     size_t result_ft = ft_strlcat(dest_ft, src, dstsize);
//     size_t result_str = strlcat(dest_str, src, dstsize);

//printf("Result of ft_strlcat:%zu,Concatenated string:%s\n",result_ft,dest_ft);
//printf("Result of strlcat: %zu,Concatenated string:%s\n",result_str,dest_str);

//     if (strcmp(dest_ft, dest_str) == 0) {
//         printf("Output is same for both functions.\n");
//     } else {
//         printf("Output differs between functions.\n");
//     }
// }

// int main() {
//     char dest[20] = "Hello ";
//     const char *src = "World!";

//     printf("Test 1: dstsize is large enough\n");
//     test_functions(dest, src, 20);
//     printf("\nTest 2: dstsize is exactly the length of dest\n");
//     test_functions(dest, src, 11);

//     printf("\nTest 3: dstsize is less than the length of dest\n");
//     test_functions(dest, src, 6);

//     printf("\nTest 4: Concatenating with empty dest\n");
//     char empty_dest[20] = "";
//     test_functions(empty_dest, src, 20);

//     printf("\nTest 5: Concatenating with empty src\n");
//     char empty_src[20] = "";
//     test_functions(dest, empty_src, 20);

//     printf("\nTest 6: Concatenating with both empty dest and src\n");
//     test_functions(empty_dest, empty_src, 20);

//     printf("\nTest 7: Concatenating with src longer than dstsize\n");
//     test_functions(dest, "This is a long string", 7);

//     printf("\nTest 8: Concatenating with overlapping dest and src\n");
//     char overlapping_dest_src[20] = "HelloWorld!";
//     test_functions(overlapping_dest_src + 5, overlapping_dest_src, 20);

//     return 0;
// }