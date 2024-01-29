/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:13:58 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:14:07 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)(c))
			return ((void *)s + i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int key = 3;
	size_t arr_size = sizeof(arr);
	int *found = (int *)ft_memchr(arr, key, arr_size);
    
	if (found != NULL) {
		printf("Value found at index: %ld\n", (found - arr));
	} else {
		printf("Value not found.\n");
	}
	return 0;
}*/