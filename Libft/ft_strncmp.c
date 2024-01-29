/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:13:32 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:13:34 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "Hello Good Morning!";
	char	s2[] = "Hello Good Afternoon!";
	int	result;

	result = ft_strncmp(s1,s2,12);

	if (result == 0)
		printf("s1 and s2 are equal\n");
	if (result < 0)
		printf("s1 is less than s2 (%d)\n", result);
	if (result > 0)
		printf("s1 is greater than s2 (%d)\n", result);
}*/