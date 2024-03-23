/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:23:13 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/20 23:23:20 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

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
	if (!ft_parser(argc, &argv))
		return (1);
	if (!ft_initial_stack(&stack_a, argv))
		ft_lstclear(&stack_a, ft_clear_content);
	if (argc == 2)
		ft_free_array(argv);
	get_input(&stack_a, &stack_b);
	ft_lstclear(&stack_a, ft_clear_content);
	ft_lstclear(&stack_b, ft_clear_content);
	return (0);
}
