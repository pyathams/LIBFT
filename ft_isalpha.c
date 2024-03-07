/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:32:33 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/29 18:17:16 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>
/*isalpha()
checks  for an alphabetic character; in the standard "C" locale,
it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
cales, there may be additional characters for which isalpha() is
true—letters which are neither uppercase nor lowercase.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int	main(void)
{
	int c;
	c = 97;

	printf("%d\n",ft_isalpha(c));
	printf("%d",isalpha(c));
	return (0);
}*/