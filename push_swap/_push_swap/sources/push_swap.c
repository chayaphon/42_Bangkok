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

int	ft_updown_cost(t_list *fst_node, t_list *lst_node, int point, int mode)
{
	int	up_cost;
	int	down_cost;
	int	index;

	up_cost = 0;
	down_cost = 1;
	while (fst_node)
	{
		index = *(int *)fst_node->index;
		if ((mode == 0 && index < point) || (mode != 0 && index > point))
			break ;
		up_cost++;
		fst_node = fst_node->next;
	}
	while (lst_node)
	{
		index = *(int *)lst_node->index;
		if ((mode == 0 && index < point) || (mode != 0 && index > point))
			break ;
		down_cost++;
		lst_node = lst_node->prev;
	}
	if (up_cost <= down_cost)
		return (1);
	return (0);
}

void	ft_move_a(t_list **node_a, t_list **node_b, int *mid_point)
{
	int	num;

	num = 1;
	while (*mid_point)
	{
		num = *mid_point - num;
		while (num--)
		{
			if (*(int *)(*node_a)->index < *mid_point)
				ft_push(node_a, node_b, "pb");
			else
			{
				if (ft_updown_cost(*node_a, ft_lstlast(*node_a), *mid_point, 0))
					while (*(int *)(*node_a)->index >= *mid_point)
						ft_rotate_single(node_a, "ra");
				else
					while (*(int *)(*node_a)->index >= *mid_point)
						ft_rotate_reverse_single(node_a, "rra");
				ft_push(node_a, node_b, "pb");
			}
		}
		num = *mid_point++;
	}
}

void	ft_move_b(t_list **node_a, t_list **node_b)
{
	int	point;

	if (!ft_is_top_sorted(*node_a))
		ft_swap_single(node_a, "sa");
	while (*node_b)
	{
		if (ft_top_gap(*node_a) == 1)
			point = *(int *)(*node_a)->index - 3;
		else
			point = *(int *)(*node_a)->index;
		if (*(int *)(*node_b)->index > point)
			ft_push(node_b, node_a, "pa");
		else
		{
			if (ft_updown_cost(*node_b, ft_lstlast(*node_b), point, 1))
				while (*(int *)(*node_b)->index <= point)
					ft_rotate_single(node_b, "rb");
			else
				while (*(int *)(*node_b)->index <= point)
					ft_rotate_reverse_single(node_b, "rrb");
			ft_push(node_b, node_a, "pa");
		}
		if (!ft_is_top_sorted(*node_a))
			ft_swap_single(node_a, "sa");
	}
}

void	ft_push_swap(t_list **node_a, t_list **node_b, int argc, char **argv)
{
	int	*mid_point_array;

	if (!ft_parser(argc, &argv))
		return ;
	if (!ft_initial_stack(node_a, argv))
		ft_lstclear(node_a, ft_clear_content);
	if (argc == 2)
		free(argv);
	if (!ft_is_all_sorted(*node_a))
	{
		if (ft_lstsize(*node_a) <= 3)
			ft_sort_three(node_a);
		else
		{
			mid_point_array = ft_gerate_midpoint(*node_a);
			ft_move_a(node_a, node_b, mid_point_array);
			free(mid_point_array);
			ft_move_b(node_a, node_b);
		}
	}
}
