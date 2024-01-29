/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:07:06 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:07:10 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
		((char *)s)[i++] = 0;
}

/*
#include <stdio.h>
#include <string.h>
int main(void) {
    char myArray1[6] = "Hello";
    char myArray2[6] = "Hello";

    bzero(myArray1, 6);
    ft_bzero(myArray2, 6);

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