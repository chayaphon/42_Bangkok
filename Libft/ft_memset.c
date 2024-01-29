/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:06:34 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:06:38 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
		((char *)b)[i++] = c;
	return (b);
}

/*
#include <stdio.h>
#include <string.h>
int main(void) {
    char myArray1[6] = "Hello";
    char myArray2[6] = "Hello";

    memset(myArray1, 0, 6);
    ft_memset(myArray2, 0, 6);

    int i = 0;
    while (i < 6)
    {
        printf("myArray1[%d] = %d\n", i, myArray1[i]);
        printf("myArray2[%d] = %d\n", i, myArray2[i]);
        i++;
    }
    printf("myArray1 %s\n", myArray1);
    printf("myArray2 %s\n", myArray2);
}*/