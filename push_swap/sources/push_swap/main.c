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

#include "push_swap.h"

void	ft_clear_content(void *content)
{
	free (content);
}

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
