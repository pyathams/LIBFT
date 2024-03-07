/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:30:16 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/06 13:50:17 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <unistd.h>
/*
Function name ft_putchar_fd
Prototype void ft_putchar_fd(char c, int fd);
Turn in files -
Parameters c: The character to output.
fd: The file descriptor on which to write.
Return value None
External functs. write
Description Outputs the character ’c’ to the given file
descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('C',0);
// }