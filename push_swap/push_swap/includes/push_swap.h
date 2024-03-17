/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:39:38 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/14 22:39:46 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"

void	ft_push_swap(t_list **node_a, t_list **node_b, int argc, char **argv);
void	ft_push(t_list **node1, t_list **node2, char *str);
void	ft_swap_single(t_list **node, char *str);
void	ft_swap_both(t_list **node_a, t_list **node_b);
void	ft_rotate_single(t_list **node, char *str);
void	ft_rotate_both(t_list **node_a, t_list **node_b);
void	ft_rotate_reverse_single(t_list **node, char *str);
void	ft_rotate_reverse_both(t_list **node_a, t_list **node_b);
int		ft_initial_stack(t_list **node, char **val);
int		ft_index_sorting(t_list *node, int node_len);
int		ft_is_sorted(t_list *stack);
int	    ft_parser(int argc, char ***argv);
void	ft_clear_content(void *content);
t_list	*ft_create_node(int index_val, int content_val);
void    ft_operation(t_list **node_a, t_list **node_b, int *mid_point_array);
int     ft_is_top_sorted(t_list *stack);

void	ft_print_node(t_list *node);
void	ft_print_node_reverse(t_list *node);

#endif