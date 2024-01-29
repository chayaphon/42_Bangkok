/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:14:57 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:15:00 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (!haystack[0] || len == 0)
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && ((i + j) < len))
		{
			if (!needle[j + 1])
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    const char *haystack = "Hello, world!";
    const char *needle = "world";

    size_t len = 12; 
    char *result = ft_strnstr(haystack, needle, len);
    if (result != NULL) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found within the first %zu characters.\n", len);
    }
    return 0;
}*/