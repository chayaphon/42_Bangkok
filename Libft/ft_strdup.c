/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:21:53 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:21:57 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc((sizeof(char) * ft_strlen(s1)) + 1);
	if (dest == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int	main() {
	char *ori_str = "Hello, World!";
	char *dup_str = ft_strdup(ori_str);

	if (dup_str != NULL)
	{
		printf("Original: %s\n", ori_str);
		printf("Duplicate: %s\n", dup_str);
		free(dup_str);
	}
	else
        printf("Memory allocation failed.\n");
    return 0;
}*/