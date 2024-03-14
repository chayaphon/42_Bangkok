/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:56:46 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/15 01:56:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_initial_stack(t_list **node, char **val)
{
	int *index;
	int *content;
	int	i;

	i = 0;
	while(val[i])
	{
		index = malloc(sizeof(int));
		content = malloc(sizeof(int));
		*index = i+1;
		*content = ft_atoi(val[i]);
		t_list *new_lst = ft_lstnew(index, content);
		ft_lstadd_back(node, new_lst);
		i++;
	}
}

void ft_print_node(t_list *node)
{
	t_list *temp;

	temp = node;
	while (temp)
	{
		ft_printf("Index: %d Content: %d\n", *(int *)(temp->index), *(int *)(temp->content));
		temp = temp->next;
	}
}
