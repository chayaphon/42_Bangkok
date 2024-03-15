/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:56:46 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/15 01:56:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_index_sorting(t_list *node, int node_len)
{
	int		i;
	int		min;
	t_list	*lst;
	t_list	*min_node;

	i = 0;
	while (++i <= node_len)
	{
		lst = node;
		min = 2147483647;
		while (lst)
		{
			if (*(int *)lst->index == 0 && *(int *)lst->content < min)
			{
				min = *(int *)lst->content;
				min_node = lst;
			}
			lst = lst->next;
		}
		if (min_node)
			*(int *)min_node->index = i;
	}
	return (1);
}

t_list	*ft_create_and_init_node(int index_val, char *content_val)
{
	int		*index;
	int		*content;
	t_list	*new_lst;

	index = malloc(sizeof(int));
	content = malloc(sizeof(int));
	if (!index || !content)
	{
		free(index);
		free(content);
		return (0);
	}
	*index = index_val;
	*content = ft_atoi(content_val);
	new_lst = ft_lstnew(index, content);
	if (!new_lst)
	{
		free(index);
		free(content);
		return (0);
	}
	return (new_lst);
}

int	ft_initial_stack(t_list **node, char **val)
{
	t_list	*new_lst;
	int		i;

	i = -1;
	while (val[++i])
	{
		new_lst = ft_create_and_init_node(0, val[i]);
		if (!new_lst)
			return (0);
		ft_lstadd_back(node, new_lst);
	}
	if (!ft_index_sorting(*node, ft_lstsize(*node)))
		return (0);
	return (1);
}

void	ft_print_node(t_list *node)
{
	t_list	*temp;

	temp = node;
	while (temp)
	{
		ft_printf("Index: %d ", *(int *)(temp->index));
		ft_printf("Content: %d\n", *(int *)(temp->content));
		temp = temp->next;
	}
}
