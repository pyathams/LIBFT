/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:46:30 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/06 23:58:15 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
/*
DESCRIPTION
       The  atoi() function converts the initial portion of
       the string pointed to by nptr to int.  The  behavior
       is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

       The  atol() and atoll() functions behave the same as
       atoi(), except that they convert the initial portion
       of  the  string to their return type of long or long
       long.

RETURN VALUE
       The converted value or 0 on error.
*/

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

// int	main(void)
// {
// 	char *str = "\t\n\r\v\f  469 \n";
// 	printf("%i \n",atoi(str));
// 	printf("%i",ft_atoi(str));
// 	return (0);
// }
