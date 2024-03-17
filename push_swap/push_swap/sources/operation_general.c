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

void	ft_clear_content(void *content)
{
	free (content);
}

int	ft_index_sorting(t_list *node, int node_len)
{
	int		i;
	int		min;
	t_list	*lst;
	t_list	*min_node;

	i = 0;
	min_node = NULL;
	while (++i <= node_len)
	{
		lst = node;
		min = INT_MAX;
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

t_list	*ft_create_node(int index_val, int content_val)
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
	*content = content_val;
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
		new_lst = ft_create_node(0, ft_atoi(val[i]));
		if (!new_lst)
			return (0);
		ft_lstadd_back(node, new_lst);
	}
	if (!ft_index_sorting(*node, ft_lstsize(*node)))
		return (0);
	return (1);
}

int	ft_is_all_sorted(t_list *stack)
{
	int	prev_index;
	int i;

	i = 0;
	prev_index = 0;
	while (stack)
	{
		if (*(int *)stack->index < prev_index)
			return (0);
		prev_index = *(int *)stack->index;
		stack = stack->next;
	}
	return (1);
}

int	ft_is_top_sorted(t_list *stack)
{
	int	top_index;
	int i;

	i = 1;
	top_index = *(int *)stack->index;
	stack = stack->next;
	if (*(int *)stack->index < top_index)
		return (0);
	return (1);
}
