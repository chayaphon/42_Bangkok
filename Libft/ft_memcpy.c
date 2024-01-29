/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:07:41 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:07:44 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_n;
	const char	*src_n;

	if (!dst && !src)
		return (0);
	dst_n = (char *)dst;
	src_n = (const char *)src;
	while (n--)
		dst_n[n] = src_n[n];
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    char src[] = "Hello, world!";
    char dest[50];

    ft_memcpy(dest, src, strlen(src) +1);  // +1 to include the null-terminator
    printf("Copied string: %s\n", dest);
    return 0;
}*/