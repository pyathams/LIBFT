/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:01:09 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/12 17:52:24 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trim(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return (ft_strdup(""));
	while (ft_trim(set, s1[i]))
		i++;
	while (ft_trim(set, s1[j]))
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}

// int	main(void)
// {
// 	printf("%s",ft_strtrim("aabbbbbthis is prashanthbbbbaaabbbaaab","ab"));
// }