/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:08:40 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:08:42 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "Hello World";
	char	dest1[] = "Good Morning";
	char	dest2[] = "Good Morning";
	size_t	count1;
	size_t	count2;

	count1 = strlcpy(dest1, src, 4);
	count2 = ft_strlcpy(dest2, src, 4);
	printf("std : count %ld\nsoruce %s\ndest %s\n",count1,src,dest1);
	printf("ft_ : count %ld\nsoruce %s\ndest %s\n",count2,src,dest2);
}*/