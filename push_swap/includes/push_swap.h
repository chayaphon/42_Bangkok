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

# include "../libft/includes/libft.h"

void	ft_push_swap(t_list **node_a, t_list **node_b, int argc, char **argv);
void	ft_push(t_list **node1, t_list **node2, int chunk, char *str);
void	ft_swap_single(t_list **node, char *str);
void	ft_swap_both(t_list **node_a, t_list **node_b, char *str);
void	ft_rotate_single(t_list **node, char *str);
void	ft_rotate_both(t_list **node_a, t_list **node_b, char *str);
void	ft_rotate_reverse_single(t_list **node, char *str);
void	ft_rotate_reverse_both(t_list **node_a, t_list **node_b, char *str);
void	ft_clear_content(void *content);
void	ft_free_array(char **str);
void	ft_top_correction(t_list **node_a, t_list **node_b, int mode);
int		ft_parser(int argc, char ***argv);
int		ft_initial_stack(t_list **node, char **val);
int		ft_index_sorting(t_list *node, int node_len);
int		ft_midpoint(t_list *node, int chunk);
int		ft_updown_cost(t_list *fst_node, t_list *lst_node, int point, int mode);
int		ft_num_exist(t_list *node, int midpoint, int chunk, int mode);
int		ft_max_chunk(t_list *node);
int		ft_is_all_sorted(t_list *stack);
int		ft_is_top_sorted(t_list *stack, int mode);
int		ft_is_chunk_sort(t_list *node, int chunk);
int		ft_top_gap(t_list *stack);
int		ft_min_index(t_list *node, int chunk);
int		ft_new_chunk(t_list *node_a, t_list *node_b);

#endif