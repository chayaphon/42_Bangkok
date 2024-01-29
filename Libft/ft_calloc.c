/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:21:41 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:21:42 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(size * count);
	if (!result)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    size_t num = 5;

	//arr = (int*)calloc(num, sizeof(int));
    arr = (int*)ft_calloc(num, sizeof(int));
    if (arr == NULL)
        printf("Memory allocation failed!\n");
    for (size_t i = 0; i < num; ++i)
        printf("arr[%zu] = %d\n", i, arr[i]); 
    free(arr);
    return (0);
}*/