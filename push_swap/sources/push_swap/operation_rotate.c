/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:05:52 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/14 23:05:55 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_node(t_list **node)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*node) <= 1)
		return ;
	first = *node;
	last = ft_lstlast(*node);
	*node = first->next;
	(*node)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ft_rotate_single(t_list **node, char *str)
{
	ft_rotate_node(node);
	if (*str)
		ft_printf("%s\n", str);
}

void	ft_rotate_both(t_list **node_a, t_list **node_b, char *str)
{
	ft_rotate_node(node_a);
	ft_rotate_node(node_b);
	if (*str)
		ft_printf("%s\n", str);
}
