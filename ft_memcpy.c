/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:54:01 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/09 18:10:40 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <unistd.h>
// #include <stddef.h>
/*DESCRIPTION
       The  memcpy()  function copies n bytes from memory
       area src to memory area dest.   The  memory  areas
       must  not  overlap.   Use memmove(3) if the memory
       areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;
	const char		*source;

	if (!dest && !src)
		return (NULL);
	ret = (unsigned char *)dest;
	source = (const char *)src;
	while (n--)
	{
		*ret++ = *source++;
	}
	return (dest);
}

// int	main(void)
// {
// 	//char str[] = "";
// 	//char des[12] = "";
// 	char str1[]= "hello";
// 	char des1[12];

// 	printf("%p\n", ft_memcpy(des1,str1,sizeof(char)*12));
// 	printf("%s\n",des1);
// 	printf("%p\n",memcpy(des1,str1,sizeof(char)*12));
// 	printf("%s\n",des1);
// 	return (0);
// }
