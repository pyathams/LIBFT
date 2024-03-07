/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:02:32 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/06 19:16:40 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>
//
//void	*ft_memset(void *s, int c, size_t n);
/*
DESCRIPTION
       The  bzero()  function erases the data in the n bytes
       of the memory starting at the location pointed to  by
       s,  by  writing zeros (bytes containing '\0') to that
       area.

       The explicit_bzero() function performs the same  task
       as bzero().  It differs from bzero() in that it guar‐
       antees that compiler optimizations  will  not  remove
       the  erase operation if the compiler deduces that the
       operation is "unnecessary".

RETURN VALUE
       None.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int	main(void)
// {
// 	char	str[10];
// 	char	str1[10];
// 	ft_bzero(str, 10);
// 	bzero(str1, 10);
// 	printf("%s \n", str);
// 	printf("%s\n", str1);
// 	return (0);
// }