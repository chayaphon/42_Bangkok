/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:05:52 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/14 23:05:55 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_node(t_list **node)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(node) <= 1)
		return ;
	first = *node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*node = second;
}

void	ft_swap_single(t_list **node, char *str)
{
	ft_swap_node(node);
	ft_printf("%s\n", str);
}

void	ft_swap_both(t_list **node_a, t_list **node_b)
{
	ft_swap_node(node_a);
	ft_swap_node(node_b);
	ft_printf("ss\n");
}
