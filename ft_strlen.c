/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:49:01 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/29 21:33:58 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
/*
DESCRIPTION
       The  strlen()  function  calcu‐
       lates  the length of the string
       pointed to by s, excluding  the
       terminating null byte ('\0').

RETURN VALUE
       The  strlen()  function returns
       the  number  of  bytes  in  the
       string pointed to by s.
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	*s;

	s = "hello world";
	printf("%ld\n",ft_strlen(s));
	printf("%ld",strlen(s));
	return (0);
}*/
