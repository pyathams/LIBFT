/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:04 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/06 19:20:36 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(src);
	if (size < 1)
		return (count);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

// int	main(void)
// {
// 	char		dest[50]= "";
// 	const char	src[50]= "";
// 	size_t		i;

// 	i = ft_strlcpy(dest,src,18);
// 	printf("%s\n",dest);
// 	printf("%ld",i);
// 	return (0);
// }