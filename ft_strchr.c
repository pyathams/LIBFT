/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:31:32 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/03 23:11:04 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
/*
DESCRIPTION
       The strchr() function returns  a  pointer  to  the
       first  occurrence of the character c in the string
       s.

       The strrchr() function returns a  pointer  to  the
       last  occurrence  of the character c in the string
       s.
char *strrchr(const char *s, int c); at the end of  s,  rather
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (!*s++)
		{
			return (NULL);
		}
	}
	return ((char *)s);
}
/*
int	main(void)
{
	char tweet[] = "this is my @mention";
	char *mention = strchr(tweet,'@');
	char *mention1 = ft_strchr(tweet,'@');
	
	printf("%s\n", mention);
	printf("%p\n",tweet + 11);
	printf("%s\n", mention1);
	printf("%p\n",tweet + 11);
	if(strchr(tweet,'#') == 0)
		printf("strchr returned null\n");
	if(ft_strchr(tweet,'#') == 0)
		printf("strchr returned null");
}*/