/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:27 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/08 10:43:18 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (0);
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (save);
}

/*
#include <stdio.h>
#include <stdlib.h>
void *increment_content(void *content)
{
    int *new_content = malloc(sizeof(int));
    *new_content = *(int *)content + 1;
    return new_content;
}

void simple_del(void *content)
{
    free(content);
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

    printf("Original List:\n");
    print_list(lst1);

    t_list *mapped_list = ft_lstmap(lst1, increment_content, simple_del);

    printf("Mapped List:\n");
    print_list(mapped_list);

    // Freeing memory
    ft_lstclear(&lst1, simple_del);
    ft_lstclear(&mapped_list, simple_del);

    return 0;
}*/
