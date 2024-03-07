/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:19:32 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/29 18:30:44 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>
/*
isascii()
checks whether c is a 7-bit unsigned char value that  fits  into
the ASCII character set.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	printf("%d\n", ft_isascii(127));
	printf("%d\n", isascii(127));
	printf("%d\n", ft_isascii(100));
	printf("%d\n", ft_isascii(250));
	printf("%d\n", isascii(250));
}*/
