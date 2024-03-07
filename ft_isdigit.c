/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:40:06 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/29 18:35:26 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>
/*
isdigit()
checks for a digit (0 through 9).
*/

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
int	main(void)
{
	printf("%d\n",ft_isdigit(48));
	printf("%d\n",ft_isdigit(58));
	printf("%d\n",isdigit(48));
	printf("%d\n",isdigit(58));

}*/
