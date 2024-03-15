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

#include "../includes/push_swap.h"

void	ft_rotate_reverse_node(t_list **node)
{
	t_list	*last;
	t_list	*second_to_last;

	if (ft_lstsize(*node) <= 1)
		return ;
	last = *node;
	second_to_last = NULL;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *node;
	*node = last;
}

void	ft_rotate_reverse_single(t_list **node, char *str)
{
	ft_rotate_reverse_node(node);
	ft_printf("%s\n", str);
}

void	ft_rotate_reverse_both(t_list **node_a, t_list **node_b)
{
	ft_rotate_reverse_node(node_a);
	ft_rotate_reverse_node(node_b);
	ft_printf("rr\n");
}
