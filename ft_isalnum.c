/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:00:09 by pyathams          #+#    #+#             */
/*   Updated: 2024/02/29 19:20:19 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>
/*isalnum()
checks for an alphanumeric character; it is equivalent to 
(isalpha(c) || isdigit(c)).*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main(void)
{
	printf("%d \n", ft_isalnum(90));
	printf("%d \n", isalnum(90));
	printf("%d \n", ft_isalnum(48));
	printf("%d \n", isalnum(48));
	printf("%d \n", ft_isalnum(46));
	printf("%d \n", isalnum(46));
	printf("%d \n", ft_isalnum(127));
	return (0);
}*/
