/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
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
	min_node = NULL;
	while (++i <= node_len)
	{
		lst = node;
		min = INT_MAX;
		while (lst)
		{
			if (*(int *)lst->index == 0 && *(int *)lst->content <= min)
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

int	ft_is_all_sorted(t_list *stack)
{
	int	prev_index;

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

	top_index = *(int *)stack->index;
	stack = stack->next;
	if (*(int *)stack->index < top_index)
		return (0);
	return (1);
}

int	ft_top_gap(t_list *stack)
{
	int	top_index;
	int	gap;

	top_index = *(int *)stack->index;
	stack = stack->next;
	gap = top_index - *(int *)stack->index;
	if (gap < 0)
		gap *= -1;
	return (gap);
}

void	ft_sort_three(t_list **stack)
{
	while (!ft_is_all_sorted(*stack))
	{
		if (!ft_is_top_sorted(*stack))
			ft_swap_single(stack, "sa");
		else
			ft_rotate_reverse_single(stack, "rra");
	}
}
