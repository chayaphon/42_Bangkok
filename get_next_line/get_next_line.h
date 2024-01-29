/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:06:35 by csorntha          #+#    #+#             */
/*   Updated: 2023/10/10 17:09:49 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*read_line(int fd, t_list **list);
char	*get_data(t_list *list, t_list **p_list);
void	add_list(t_list **list, char *data);
void	clean_list(t_list **list);
void	clear_list(t_list **list);
int		is_break(t_list *list);
char	*read_remain_word(t_list *list);
int		get_len(t_list *list);
t_list	*find_last_node(t_list *list);

#endif