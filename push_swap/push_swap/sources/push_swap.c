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

int ft_check_cost(t_list *node, int midpoint)
{
	int up_cost;
	int down_cost;
	int cost;
	int size;

	size = ft_lstsize(node);
	cost = 0;
	up_cost = 0;
	down_cost = 0;
	while (node)
	{
		if (*(int *)node->index < midpoint && up_cost == 0)
			up_cost = cost;
		if (*(int *)node->index < midpoint)
			down_cost = cost;
		node = node->next;
		cost++;
	}
	down_cost = size - down_cost;
	if (up_cost <= down_cost)
		return (1);
	return (0);
}

void ft_move_a(t_list **node_a, t_list **node_b, int num, int midpoint)
{
	while (num--)
	{
		if (*(int *)(*node_a)->index < midpoint)
			ft_push(node_a, node_b, "pb");
		else
		{
			if (ft_check_cost(*node_a, midpoint))
				while (*(int *)(*node_a)->index >= midpoint)
					ft_rotate_single(node_a, "ra");
			else
				while (*(int *)(*node_a)->index >= midpoint)
					ft_rotate_reverse_single(node_a, "rra");
			ft_push(node_a, node_b, "pb");
		}
	}
}

void ft_move_b(t_list **node_b, t_list **node_a, int num, int midpoint)
{
	int i;

	i = 0;
	while (num--)
	{
		while (*(int *)(*node_b)->index <= midpoint)
		{
			ft_rotate_single(node_b, "rb");
			i++;
		}
		ft_push(node_b, node_a, "pa");
	}
	while (i--)
		ft_rotate_reverse_single(node_b, "rrb");
}

void ft_reverse_array(int *array)
{
	int i;
	int j;
	int	temp;

	i = 0;
	j = 0;
	while (array[j])
		j++;
	j--;
	while(i < j)
	{
		temp = array[i];
		array[i++] = array[j];
		array[j--] = temp;
	}
}

void ft_push_swap(t_list **node_a, t_list **node_b, int argc, char **argv)
{
	int *mid_point_array;

	if (!ft_parser(argc, &argv))
		return;
	if (!ft_initial_stack(node_a, argv))
		ft_lstclear(node_a, ft_clear_content);
	if (argc == 2)
		free(argv);
	mid_point_array = ft_gerate_midpoint(*node_a);
	ft_operation(node_a, node_b, mid_point_array);

	// while (!ft_is_all_sorted(*node_a))
}

void ft_operation(t_list **node_a, t_list **node_b, int *mid_point_array)
{
	int num;

	num = 1;
	while (*mid_point_array)
	{
		num = *mid_point_array - num;
		ft_move_a(node_a, node_b, num, *mid_point_array);
		num = *mid_point_array++;
	}
	if (!ft_is_top_sorted(*node_a))
		ft_rotate_single(node_a, "ra");
	ft_push(node_b, node_a, "pa");

	// num = ft_lstsize(*node_b) + 2;
	// while (mid_lst_last)
	// {
	// 	num = (*(int *)mid_lst_last->content - num) * -1;
	// 	ft_printf("num : %d\n", num);
	// 	// ft_printf("midpoint : %d\n", *(int *)mid_lst_last->content );
	// 	ft_printf("midpoint : %d\n", *(int *)mid_lst_last->content - 2);
	// 	// ft_move_b(node_a, node_b, num, *(int *)mid_lst_last->content - 2);
	// 	num = *(int *)mid_lst_last->content;
	// 	mid_lst_last = mid_lst_last->prev;
	// }
}
