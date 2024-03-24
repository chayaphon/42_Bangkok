/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:39:38 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/14 22:39:46 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/includes/libft.h"
# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_lstbuff
{
	char				*str_buf;
	struct s_lstbuff	*next;
}	t_buff;

void	get_input(t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
char	*read_line(int fd, t_buff **list);
char	*get_data(t_buff *list, t_buff **p_list);
void	add_list(t_buff **list, char *data);
void	clean_list(t_buff **list);
void	clear_list(t_buff **list);
int		is_break(t_buff *list);
char	*read_remain_word(t_buff *list);
int		get_len(t_buff *list);
t_buff	*find_last_node(t_buff *list);

#endif