/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:30:25 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/08 10:31:19 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "./ft_lstnew.c"

int main()
{
    int data1 = 42;
    int data2 = 100;
    int data3 = 200;

    t_list *lst1 = ft_lstnew(&data1);
    t_list *lst2 = ft_lstnew(&data2);
    t_list *lst3 = ft_lstnew(&data3);

    lst1->next = lst2;
    lst2->next = lst3;

    printf("Size of the list: %d\n", ft_lstsize(lst1));

    free(lst1);
    free(lst2);
    free(lst3);

    return 0;
}*/