/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:31:02 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/09 17:25:17 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
/*
DESCRIPTION
       The  memmove()  function  copies n bytes from memory
       area src to memory area dest.  The memory areas  may
       overlap:  copying takes place as though the bytes in
       src are first copied into  a  temporary  array  that
       does not overlap src or dest, and the bytes are then
       copied from the temporary array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*res;
	const char	*source;

	res = (char *)dest;
	source = (const char *)src;
	if (dest > src && dest < src + len)
	{
		while (len--)
		{
			res[len] = source[len];
		}
	}
	else
	{
		ft_memcpy(dest, src, len);
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*src;
// 	char	*dest;

// 	src = "hello world!";
// 	dest = (char *)malloc(sizeof(char) * ft_strlen(src));
// 	printf("%p\n",src);
// 	printf("%p\n", dest);
// 	printf("%p \n",memmove(dest, src, sizeof(char) * (ft_strlen(src) + 1)));
// 	printf("%s\n",dest);
// 	printf("%s",src);
// 	printf("%p\n",src);
// 	printf("%p\n", dest);
// 	printf("%p \n",ft_memmove(dest, src, sizeof(char) * (ft_strlen(src) + 1)));
// 	printf("%s\n",dest);
// 	printf("%s",src);
// }