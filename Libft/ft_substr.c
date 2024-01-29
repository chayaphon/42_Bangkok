/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:26:54 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:27:44 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sublen;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		sublen = 0;
	else if ((ft_strlen(s) - start) >= len)
		sublen = len;
	else
		sublen = (ft_strlen(s) - start);
	str = (char *)malloc(sizeof(*s) * (sublen + 1));
	if (!str)
		return (0);
	while (i < sublen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include<stdio.h>
int	main(void)
{
	char str[] = "Hello World!!";
	char *s;

	s = ft_substr(str,6,5);
	printf("%s\n", s);
}*/