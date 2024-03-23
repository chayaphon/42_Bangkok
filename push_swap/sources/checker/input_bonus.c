/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:23:13 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/20 23:23:20 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	operate_input(char *input, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(input, "sa\n", 3))
		ft_swap_single(stack_a, "");
	else if (!ft_strncmp(input, "sb\n", 3))
		ft_swap_single(stack_b, "");
	else if (!ft_strncmp(input, "ss\n", 3))
		ft_swap_both(stack_a, stack_b, "");
	else if (!ft_strncmp(input, "pa\n", 3))
		ft_push(stack_b, stack_a, 0, "");
	else if (!ft_strncmp(input, "pb\n", 3))
		ft_push(stack_a, stack_b, 0, "");
	else if (!ft_strncmp(input, "ra\n", 3))
		ft_rotate_single(stack_a, "");
	else if (!ft_strncmp(input, "rb\n", 3))
		ft_rotate_single(stack_b, "");
	else if (!ft_strncmp(input, "rr\n", 3))
		ft_rotate_both(stack_a, stack_b, "");
	else if (!ft_strncmp(input, "rra\n", 4))
		ft_rotate_reverse_single(stack_a, "");
	else if (!ft_strncmp(input, "rrb\n", 4))
		ft_rotate_reverse_single(stack_b, "");
	else if (!ft_strncmp(input, "rrr\n", 4))
		ft_rotate_reverse_both(stack_a, stack_b, "");
	else
		return (0);
	return (1);
}

void	get_input(t_list **stack_a, t_list **stack_b)
{
	char	buffer[5];

	ft_memset(buffer, '\0', 4);
	while (read(0, buffer, 4))
	{
		if (ft_strrchr(buffer, '\n'))
		{
			if (!operate_input(buffer, stack_a, stack_b))
			{
				write(2, "Error\n", 6);
				return ;
			}
		}
		ft_memset(buffer, '\0', 4);
	}
	if (ft_is_all_sorted(*stack_a) && !(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
