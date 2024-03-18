/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:38:49 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/14 22:38:53 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_push_swap(&stack_a, &stack_b, argc, argv);
	ft_lstclear(&stack_a, ft_clear_content);
	ft_lstclear(&stack_b, ft_clear_content);
	return (0);
}

/*
void	ft_print_node(t_list *node)
{
	t_list	*temp;

	temp = node;
	while (temp)
	{
		ft_printf("Index: %d ", *(int *)(temp->index));
		ft_printf("Content: %d\n", *(int *)(temp->content));
		temp = temp->next;
	}
}

void	ft_print_node_reverse(t_list *node)
{
	t_list	*temp;

	temp = ft_lstlast(node);
	while (temp)
	{
		ft_printf("Index: %d ", *(int *)(temp->index));
		ft_printf("Content: %d\n", *(int *)(temp->content));
		temp = temp->prev;
	}
}

// ft_printf("Stack A\n");
// ft_print_node(stack_a);
// ft_printf("Stack B\n");
// ft_print_node(stack_b);
*/