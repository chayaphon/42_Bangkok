/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:56:46 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/15 01:56:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	ft_is_top_sorted(t_list *stack, int mode)
{
	int	top_index;
	int	second_index;

	if (!stack)
		return (1);
	if (!stack->next)
		return (1);
	top_index = *(int *)stack->index;
	stack = stack->next;
	second_index = *(int *)stack->index;
	if (second_index > top_index && mode == 0)
		return (1);
	if (*(int *)stack->index < top_index && mode == 1)
		return (1);
	return (0);
}

void	ft_top_correction(t_list **node_a, t_list **node_b, int mode)
{
	if (!ft_is_top_sorted(*node_a, 0))
	{
		if (!ft_is_top_sorted(*node_b, 1))
			ft_swap_both(node_a, node_b, "ss");
		else
			ft_swap_single(node_a, "sa");
	}
	if (mode != 0)
	{
		if (!ft_is_top_sorted(*node_b, 1))
		{
			if (!ft_is_top_sorted(*node_a, 0))
				ft_swap_both(node_a, node_b, "ss");
			else
				ft_swap_single(node_b, "sb");
		}
	}
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
