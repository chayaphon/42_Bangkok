/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:08:11 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:08:14 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

/*
#include<string.h>
#include<stdio.h>
int main() {
    char str1[] = "hello, world";
	char str2[] = "hello, world";
    
    // Move the substring "world" 2 positions to the left within the same string
	// 6 characters are 'w', 'o', 'r', 'l', 'd', '\0'
	memmove(str1 + 5, str1 + 7, 6); 
    ft_memmove(str2 + 5, str2 + 7, 6);  
    
    printf("std : %s\n", str1);
    printf("ft_ : %s\n", str2);

    return 0;
}*/