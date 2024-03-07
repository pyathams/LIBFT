/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:28:28 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/29 18:42:56 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>
/*
isprint()
checks for any printable character including space.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	printf("%d\n", ft_isprint(32));
	printf("%d\n",ft_isprint(30));
	printf("%d\n",isprint(32));
	printf("%d\n",isprint(30));
	return (0);
}*/
