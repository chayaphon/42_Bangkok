/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:50:10 by csorntha          #+#    #+#             */
/*   Updated: 2023/10/10 14:50:13 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **list)
{
	t_list	*tmp;

	if (!(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

int	is_break(t_list *list)
{
	int	i;

	i = 0;
	while (list->str_buf[i++])
	{
		if (list->str_buf[i - 1] == '\n')
			return (1);
	}
	return (0);
}

char	*read_remain_word(t_list *list)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	while (list->str_buf[i])
		if (list->str_buf[i++] == '\n')
			break ;
	if (!list->str_buf[i])
		return (NULL);
	if (i - 1 == BUFFER_SIZE)
		i = 0;
	data = malloc(BUFFER_SIZE - i + 1);
	if (!data)
		return (NULL);
	while (list->str_buf[i])
		data[j++] = list->str_buf[i++];
	data[j] = '\0';
	return (data);
}

int	get_len(t_list *list)
{
	int		i;
	int		j;

	j = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			j++;
			if (list->str_buf[i] == '\n')
				break ;
			i++;
		}
		list = list->next;
	}
	return (j);
}
