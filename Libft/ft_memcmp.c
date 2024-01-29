/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:14:29 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:14:31 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;

	src1 = (const unsigned char *)s1;
	src2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    char arr1[] = {1, 2, 3, 4, 1};
    char arr2[] = {1, 2, 3, 4, 5};

    //int result = memcmp(arr1, arr2, sizeof(arr1));
	int result = ft_memcmp(arr1, arr2, sizeof(arr1));

	if (result == 0)
		printf("s1 and s2 are equal\n");
	if (result < 0)
		printf("s1 is less than s2 (%d)\n", result);
	if (result > 0)
		printf("s1 is greater than s2 (%d)\n", result);
    return 0;
}*/