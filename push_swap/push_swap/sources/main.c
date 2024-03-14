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

void clear_content(void *content)
{
    free(content);
}

int isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int validate_input(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list 	*stack_a;
	t_list 	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv++;
	if (!validate_input(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_initial_stack(&stack_a, argv);
	ft_print_node(stack_a);
	ft_lstclear(&stack_a, clear_content);
	ft_lstclear(&stack_b, clear_content);
}