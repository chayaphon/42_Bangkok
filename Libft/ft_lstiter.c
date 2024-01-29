/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:40 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/08 10:41:16 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "./ft_lstnew.c"
void increment_content(void *content)
{
    // Increment the integer value pointed to by content
    *(int *)content += 1;
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("Content: %d\n", *(int *)(lst->content));
        lst = lst->next;
    }
}

int main(void)
{
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 42;
    *data2 = 100;

    t_list *lst1 = ft_lstnew(data1);
    t_list *lst2 = ft_lstnew(data2);
    lst1->next = lst2;

    printf("Before using ft_lstiter:\n");
    print_list(lst1);

    ft_lstiter(lst1, increment_content);

    printf("After using ft_lstiter:\n");
    print_list(lst1);

    // Freeing memory
    free(lst1->content);
    free(lst2->content);
    free(lst1);
    free(lst2);

    return 0;
}*/