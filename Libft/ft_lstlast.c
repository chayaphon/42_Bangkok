/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:31:45 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/08 10:32:30 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "./ft_lstnew.c"
#include "./ft_lstadd_back.c"
int main(void)
{
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));
    *data1 = 42;
    *data2 = 100;
    *data3 = 58;

    t_list *lst1 = ft_lstnew(data1);
    t_list *lst2 = ft_lstnew(data2);
    t_list *lst3 = ft_lstnew(data3);
    
	ft_lstadd_back(&lst1,lst2);
	ft_lstadd_back(&lst2,lst3);

    t_list *last_node = ft_lstlast(lst1);
    if (last_node)
        printf("Content of the last node: %d\n", *(int *)(last_node->content));

    free(lst1->content);
    free(lst2->content);
    free(lst3->content);
    free(lst1);
    free(lst2);
    free(lst3);
    return 0;
}*/