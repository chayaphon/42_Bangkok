/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:37:33 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/08 10:38:20 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include<stdio.h>
#include "./ft_lstnew.c"
void simple_del(void *content)
{
    free(content);
}

int main(void)
{
	int *data1 = malloc(sizeof(int));
	*data1 = 42;

	t_list *lst1 = ft_lstnew(data1);
	printf("Before deletion, content of node: %d\n", *(int *)(lst1->content));
	ft_lstdelone(lst1, simple_del);
	printf("Afeter deletion, content of node: %d\n", *(int *)(lst1->content));
	return 0;
}*/