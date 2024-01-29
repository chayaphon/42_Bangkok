/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:29 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/08 10:29:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include<stdio.h>
#include "./ft_lstnew.c"
int main(void)
{
	int *data1 = malloc(sizeof(int));
	int *data2 = malloc(sizeof(int));
	*data1 = 42;
	*data2 = 100;
	t_list *lst1 = ft_lstnew(data1);
	t_list *lst2 = ft_lstnew(data2);

	ft_lstadd_front(&lst1,lst2);
	t_list *temp = lst1;
	
	while (temp)
	{
		printf("Content of node: %d\n", *(int *)(temp->content));
		temp = temp->next;
	}
	return 0;
}*/