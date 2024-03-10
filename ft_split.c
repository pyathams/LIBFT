/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:03:20 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/09 18:14:48 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
Function name ft_split
Prototype char **ft_split(char const *s, char c);
Turn in files -
Parameters s: The string to be split.
c: The delimiter character.
Return value The array of new strings resulting from the split.
NULL if the allocation fails.
External functs. malloc, free
Description Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static void	ft_free_str_array(char **str_array)
{
	size_t	i;

	if (!str_array)
		return ;
	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return ;
}

static char	**ft_returnstr(char const *s, char c, char *start, char **res)
{
	size_t	j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			res[j] = ft_substr(start, 0, s - start);
			if (!res[j])
			{
				ft_free_str_array(res);
				return (NULL);
			}
			j++;
		}
		else
			s++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*start;

	res = ft_calloc((ft_count(s, c) + 1), sizeof(char *));
	start = NULL;
	res = ft_returnstr(s, c, start, res);
	return (res);
}
/*
#include "libft.h"
#include <stdio.h>

void print_str_array(char **str_array) {
    if (!str_array)
        return;
    
    for (int i = 0; str_array[i]; i++) {
        printf("%s\n", str_array[i]);
    }
}

int main() {
    char *input1 = "Hello World";
    char *input2 = "This is a test string";
    char *input3 = "One;Two;Three;Four;Five";
    char *input4 = "";
    char *input5 = "OnlyOneSubstring";
    
    printf("Test case 1:\n");
    printf("Expected output:\n");
    printf("Hello\nWorld\n");
    printf("Output of ft_split:\n");
    print_str_array(ft_split(input1, ' '));

    printf("\nTest case 2:\n");
    printf("Expected output:\n");
    printf("This\nis\na\ntest\nstring\n");
    printf("Output of ft_split:\n");
    print_str_array(ft_split(input2, ' '));

    printf("\nTest case 3:\n");
    printf("Expected output:\n");
    printf("One\nTwo\nThree\nFour\nFive\n");
    printf("Output of ft_split:\n");
    print_str_array(ft_split(input3, ';'));

    printf("\nTest case 4:\n");
    printf("Expected output:\n");
    printf("(Empty string)\n");
    printf("Output of ft_split:\n");
    print_str_array(ft_split(input4, ' '));

    printf("\nTest case 5:\n");
    printf("Expected output:\n");
    printf("OnlyOneSubstring\n");
    printf("Output of ft_split:\n");
    print_str_array(ft_split(input5, ' '));

    return 0;
}*/
