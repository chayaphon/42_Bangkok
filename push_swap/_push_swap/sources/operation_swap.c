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
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*node) <= 1)
		return ;
	second = (*node)->next;
	if (second->next)
	{
		third = second->next;
		third->prev = *node;
		(*node)->next = third;
	}
	else
		(*node)->next = NULL;
	(*node)->prev = second;
	second->next = *node;
	second->prev = NULL;
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

void	ft_push(t_list **node1, t_list **node2, char *str)
{
	t_list	*temp;

	if (!*node1)
		return ;
	temp = *node1;
	*node1 = (*node1)->next;
	if (*node1)
		(*node1)->prev = NULL;
	temp->next = *node2;
	if (*node2)
		(*node2)->prev = temp;
	*node2 = temp;
	ft_printf("%s\n", str);
}
