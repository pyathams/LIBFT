/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:34:23 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/08 16:00:35 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
       memset - fill memory with a constant byte

SYNOPSIS
       #include <string.h>

       void *memset(void *s, int c, size_t n);

DESCRIPTION
       The  memset() function fills the first n bytes of the memory area 
	   pointed to by s with theconstant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pt_s;

	pt_s = (unsigned char *)s;
	while (n--)
		*pt_s++ = (unsigned char)c;
	return (s);
}
// int	main(void)
// {
// 	char	str[10];
// 	int		c ;

// 	c = 97;
// 	printf("%p\n", ft_memset(str, c, 10));
// 	printf("%s \n", str);
// 	printf("%p\n", memset(str, c, 10));
// 	printf("%s", str);
// 	return (0);
// }
