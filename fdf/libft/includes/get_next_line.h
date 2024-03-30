/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:12:47 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/29 12:12:57 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_buff
{
	char			*str_buf;
	struct s_buff	*next;
}	t_buff;

char	*get_next_line(int fd);
void	clear_list(t_buff **list);
int		is_break(t_buff *list);
char	*read_remain_word(t_buff *list);
int		get_len(t_buff *list);
t_buff	*find_last_node(t_buff *list);

#endif