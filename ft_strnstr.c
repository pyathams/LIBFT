/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:30:32 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/03 23:14:46 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi‐
     nated string little in the string big, where not more than len characters
     are searched.  Characters that appear after a ‘\0’ character are not
     searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere
     in big, NULL is returned; otherwise a pointer to the first character of
     the first occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j]
			&& big[i + j] && (i + j < len))
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
void test_ft_strnstr(const char *big,
const char *little,size_t len,const char *expected)
{
    char *result = ft_strnstr(big, little, len);
if((result && expected && strcmp(result, expected) == 0)||(!result && !expected))
	{
        printf("ok");
    } else {
        printf("not ok");
    }
}

int main() {
    // Test cases
    test_ft_strnstr("Hello, world!", "Hello", 5, "Hello, world!");
    test_ft_strnstr("Hello, world!", "world", 5, NULL);
    test_ft_strnstr("Hello, world!", "world", 12, "world!");
    test_ft_strnstr("Hello, world!", "foo", 12, NULL);
    test_ft_strnstr("Hello, world!", "", 5, "Hello, world!");
    test_ft_strnstr("Hello, world!", "world", 20, "world!");
    test_ft_strnstr("Hello, world!", "Hello", 4, NULL);

    return 0;
}*/
