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

#include "push_swap.h"

void	ft_move_a(t_list **node_a, t_list **node_b, int midpoint, int chunk)
{
	int	round;
	int	track;
	int	new_chunk;

	track = 0;
	new_chunk = ft_new_chunk(*node_a, *node_b);
	round = ft_num_exist(*node_a, midpoint, chunk, 0);
	while (round--)
	{
		if (ft_updown_cost(*node_a, ft_lstlast(*node_a), midpoint, 0))
			while (*(int *)(*node_a)->index >= midpoint && ++track)
				ft_rotate_single(node_a, "ra");
		else
			while (*(int *)(*node_a)->index >= midpoint)
				ft_rotate_reverse_single(node_a, "rra");
		ft_push(node_a, node_b, new_chunk, "pb");
	}
	while (chunk && track--)
		ft_rotate_reverse_single(node_a, "rra");
}

void	ft_move_b(t_list **node_a, t_list **node_b, int midpoint, int chunk)
{
	int	round;
	int	new_chunk;

	new_chunk = ft_new_chunk(*node_a, *node_b);
	round = ft_num_exist(*node_b, midpoint, chunk, 1);
	while (round--)
	{
		if (ft_updown_cost(*node_b, ft_lstlast(*node_b), midpoint, 1))
			while (*(int *)(*node_b)->index <= midpoint)
				ft_rotate_single(node_b, "rb");
		else
			while (*(int *)(*node_b)->index <= midpoint)
				ft_rotate_reverse_single(node_b, "rrb");
		ft_push(node_b, node_a, new_chunk, "pa");
		ft_top_correction(node_a, node_b, 1);
	}
}

void	ft_move_b_simple(t_list **node_a, t_list **node_b)
{
	int	point;

	while (*node_b)
	{
		if (ft_top_gap(*node_a) == 1)
			point = *(int *)(*node_a)->index - 3;
		else
			point = *(int *)(*node_a)->index;
		if (ft_updown_cost(*node_b, ft_lstlast(*node_b), point, 1))
			while (*(int *)(*node_b)->index <= point)
				ft_rotate_single(node_b, "rb");
		else
			while (*(int *)(*node_b)->index <= point)
				ft_rotate_reverse_single(node_b, "rrb");
		ft_push(node_b, node_a, 0, "pa");
		ft_top_correction(node_a, node_b, 0);
	}
}

void	ft_stack_operation(t_list **node_a, t_list **node_b)
{
	int	chunk;

	chunk = ft_max_chunk(*node_a);
	while (ft_midpoint(*node_a, chunk))
		ft_move_a(node_a, node_b, ft_midpoint(*node_a, chunk), chunk);
	ft_top_correction(node_a, node_b, 1);
	if (ft_lstsize(*node_b) <= 100)
		ft_move_b_simple(node_a, node_b);
	while (ft_lstsize(*node_b))
	{
		chunk = ft_max_chunk(*node_a);
		if (!ft_is_chunk_sort(*node_a, chunk))
		{
			while (ft_midpoint(*node_a, chunk))
				ft_move_a(node_a, node_b, ft_midpoint(*node_a, chunk), chunk);
			ft_top_correction(node_a, node_b, 1);
		}
		chunk = ft_max_chunk(*node_b);
		if (ft_midpoint(*node_b, chunk))
			ft_move_b(node_a, node_b, ft_midpoint(*node_b, chunk), chunk);
		else
			ft_move_b(node_a, node_b, ft_min_index(*node_b, chunk) - 1, chunk);
		ft_top_correction(node_a, node_b, 1);
	}
}

void	ft_push_swap(t_list **node_a, t_list **node_b, int argc, char **argv)
{
	if (!ft_parser(argc, &argv))
		return ;
	if (!ft_initial_stack(node_a, argv))
		ft_lstclear(node_a, ft_clear_content);
	if (argc == 2)
		ft_free_array(argv);
	while (ft_lstsize(*node_a) <= 3 && !ft_is_all_sorted(*node_a))
	{
		if (!ft_is_top_sorted(*node_a, 0))
			ft_swap_single(node_a, "sa");
		else
			ft_rotate_reverse_single(node_a, "rra");
	}
	while (!ft_is_all_sorted(*node_a))
		ft_stack_operation(node_a, node_b);
}
