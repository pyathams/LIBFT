/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:42:52 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/11 17:47:54 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//include <string.h>
//#include <stdio.h>
/*
DESCRIPTION
       The  memcmp()  function compares the first n bytes (each in‐
       terpreted as unsigned char) of the memory areas s1 and s2.
RETURN VALUE
       The memcmp() function returns an integer  less  than,  equal
       to,  or  greater  than  zero  if  the first n bytes of s1 is
       found, respectively, to  be  less  than,  to  match,  or  be
       greater than the first n bytes of s2.
       For  a  nonzero  return value, the sign is determined by the
       sign of the difference between the first pair of bytes  (in‐
       terpreted as unsigned char) that differ in s1 and s2.
       If n is zero, the return value is zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		++s1;
		++s2;
	}
	return (0);
}
/*
int	main(void)
{
	 char str1[15];
   char str2[15];
   int ret;
   int ret1;

   memcpy(str1, "ABC", 6);
   memcpy(str2, "AAA", 6);

   ret = memcmp(str1, str2, 5);
   ret1 = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1\n");
   } else if(ret < 0) {
      printf("str1 is less than str2\n");
   } else {
      printf("str1 is equal to str2\n");
   }
   
	if(ret1 > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}*/
