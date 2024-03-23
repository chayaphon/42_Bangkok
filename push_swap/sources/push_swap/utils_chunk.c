/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:56:46 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/15 01:56:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_num_exist(t_list *node, int midpoint, int chunk, int mode)
{
	int	counter;

	counter = 0;
	while (node)
	{
		if (*(int *)node->chunk == chunk)
		{
			if (mode == 0 && *(int *)node->index < midpoint)
				counter++;
			if (mode == 1 && *(int *)node->index > midpoint)
				counter++;
		}
		node = node->next;
	}
	return (counter);
}

int	ft_max_chunk(t_list *node)
{
	int	max_chunk;

	max_chunk = 0;
	while (node)
	{
		if (*(int *)node->chunk > max_chunk)
			max_chunk = *(int *)node->chunk;
		node = node->next;
	}
	return (max_chunk);
}

int	ft_min_index(t_list *node, int chunk)
{
	int	min_index;

	min_index = INT_MAX;
	while (node)
	{
		if (*(int *)node->chunk == chunk)
			if (*(int *)node->index <= min_index)
				min_index = *(int *)node->index;
		node = node->next;
	}
	if (min_index == INT_MAX)
		return (0);
	return (min_index);
}

int	ft_is_chunk_sort(t_list *node, int chunk)
{
	int	prev_index;

	prev_index = 0;
	while (node)
	{
		if (*(int *)node->chunk == chunk)
		{
			if (*(int *)node->index < prev_index)
				return (0);
			prev_index = *(int *)node->index;
		}
		node = node->next;
	}
	return (1);
}

int	ft_new_chunk(t_list *node_a, t_list *node_b)
{
	int	chunk_num_a;
	int	chunk_num_b;

	chunk_num_a = ft_max_chunk(node_a);
	chunk_num_b = ft_max_chunk(node_b);
	if (chunk_num_a > chunk_num_b)
		return (chunk_num_a + 1);
	else
		return (chunk_num_b + 1);
}
