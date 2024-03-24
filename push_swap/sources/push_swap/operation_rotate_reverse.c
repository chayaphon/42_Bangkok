/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:05:52 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/14 23:05:55 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_reverse_node(t_list **node)
{
	t_list	*last;
	t_list	*new_last;

	if (ft_lstsize(*node) <= 1)
		return ;
	last = ft_lstlast(*node);
	new_last = last->prev;
	new_last->next = NULL;
	last->next = *node;
	last->prev = NULL;
	(*node)->prev = last;
	*node = last;
}

void	ft_rotate_reverse_single(t_list **node, char *str)
{
	ft_rotate_reverse_node(node);
	if (*str)
		ft_printf("%s\n", str);
}

void	ft_rotate_reverse_both(t_list **node_a, t_list **node_b, char *str)
{
	ft_rotate_reverse_node(node_a);
	ft_rotate_reverse_node(node_b);
	if (*str)
		ft_printf("%s\n", str);
}
