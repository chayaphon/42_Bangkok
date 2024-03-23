/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:56:46 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/15 01:56:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_array(char **str)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
	}
}

t_list	*ft_create_node(int index_val, int content_val, int chunk_val)
{
	int		*index;
	int		*content;
	int		*chunk;
	t_list	*new_lst;

	index = malloc(sizeof(int));
	content = malloc(sizeof(int));
	chunk = malloc(sizeof(int));
	if (index && content && chunk)
	{
		*index = index_val;
		*content = content_val;
		*chunk = chunk_val;
		new_lst = ft_lstnew(index, content, chunk);
		if (new_lst)
			return (new_lst);
	}
	free(index);
	free(content);
	free(chunk);
	return (0);
}

int	ft_initial_stack(t_list **node, char **val)
{
	t_list	*new_lst;
	int		i;

	i = -1;
	while (val[++i])
	{
		new_lst = ft_create_node(0, ft_atoi(val[i]), 0);
		if (!new_lst)
			return (0);
		ft_lstadd_back(node, new_lst);
	}
	if (!ft_index_sorting(*node, ft_lstsize(*node)))
		return (0);
	return (1);
}

int	ft_midpoint(t_list *node, int chunk)
{
	int	n;
	int	midpoint;
	int	total_num;

	n = 0;
	total_num = 0;
	while (node)
	{
		if (*(int *)node->chunk == chunk)
		{
			total_num += *(int *)node->index;
			n++;
		}
		node = node->next;
	}
	if (n <= 2)
		return (0);
	midpoint = total_num / n;
	if (total_num % n > 0)
		midpoint += 1;
	return (midpoint);
}

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
