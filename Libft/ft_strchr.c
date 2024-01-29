/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:12:48 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:12:56 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = c;
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == uc)
		return ((char *)s + i);
	return (0);
}

/*
#include<stdio.h>
int	main(void)
{
	char	*s	=	"Good Morning";
	char	c	=	'M';
	printf("result : %s\n", ft_strchr(s, c));
	return (0);
}*/