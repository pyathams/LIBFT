/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:06:53 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/28 19:29:40 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
These functions convert lowercase letters to uppercase, and vice versa.

If  c  is a lowercase letter, toupper() returns its uppercase equivalent,
if an uppercase representation exists in the current locale.  Otherwise, 
it returns c.  The toupper_l() function  performs  the same task, but uses 
the locale referred to by the locale handle locale.
If  c  is an uppercase letter, tolower() returns its lowercase equivalent,
if a lowercase representation exists in the current locale.  Otherwise,
it returns c.  The tolower_l() function  performs  the same task, but uses 
the locale referred to by the locale handle locale.
If c is neither an unsigned char value nor EOF, the behavior of these functions
is undefined.
The  behavior  of  toupper_l()  and  tolower_l()  is undefined if locale is 
the special locale object
LC_GLOBAL_LOCALE (see duplocale(3)) or is not a valid locale object handle.

RETURN VALUE
The value returned is that of the converted letter, or c if the 
conversion was not possible.
*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
