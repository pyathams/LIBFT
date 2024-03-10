/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:52:22 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/06 23:04:59 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>
/*
DESCRIPTION
       The strchr() function returns  a  pointer  to  the
       first  occurrence of the character c in the string
       s.

       The strrchr() function returns a  pointer  to  the
       last  occurrence  of the character c in the string
       s.

       The strchrnul() function is like  strchr()  except
       that  if  c  is  not found in s, then it returns a
       pointer to the null byte at the end of  s,  rather
       than NULL.

       Here  "character" means "byte"; these functions do
       not work with wide or multibyte characters.

RETURN VALUE
       The strchr()  and  strrchr()  functions  return  a
       pointer  to  the  matched character or NULL if the
       character is not found.  The terminating null byte
       is  considered part of the string, so that if c is
       specified  as  '\0',  these  functions  return   a
       pointer to the terminator.

*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			last = s;
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		last = s;
	}
	return ((char *)last);
}
/*
int	main(void)
{
	char tweet[] = "this is @my @mention";
	char *mention = strrchr(tweet,'@');
	char *mention1 = ft_strrchr(tweet,'@');
	
	printf("%s\n", mention);
	printf("%p\n",tweet + 11);
	printf("%s\n", mention1);
	printf("%p\n",tweet + 11);
	if(strrchr(tweet,'#') == 0)
		printf("strchr returned null\n");
	if(ft_strrchr(tweet,'#') == 0)
		printf("strchr returned null");
}*/
