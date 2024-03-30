/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:49:25 by csorntha          #+#    #+#             */
/*   Updated: 2023/10/10 14:49:52 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	add_list(t_buff **list, char *data)
{
	t_buff	*new_node;
	t_buff	*last_node;

	new_node = malloc(sizeof(t_buff));
	if (!new_node)
	{
		free(data);
		return ;
	}
	new_node->str_buf = data;
	new_node->next = NULL;
	last_node = find_last_node(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
}

void	clean_list(t_buff **list)
{
	char	*data;
	t_buff	*last_node;

	if (!(*list))
		return ;
	data = NULL;
	last_node = find_last_node(*list);
	if (is_break(last_node))
		data = read_remain_word(last_node);
	clear_list(list);
	if (data)
		add_list(list, data);
}

char	*get_data(t_buff *list)
{
	int		i;
	int		j;
	char	*data;

	j = 0;
	data = malloc(get_len(list) + 1);
	if (!data)
	{
		clear_list(&list);
		return (NULL);
	}
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			data[j++] = list->str_buf[i++];
			if (list->str_buf[i - 1] == '\n')
				break ;
		}
		list = list->next;
	}
	data[j] = '\0';
	return (data);
}

char	*read_line(int fd)
{
	int		char_read;	
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	char_read = read(fd, buffer, BUFFER_SIZE);
	if (char_read == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[char_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static t_buff	*list;
	char			*data;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		clear_list(&list);
		return (NULL);
	}
	while (1)
	{
		if (is_break(find_last_node(list)) == 1)
			break ;
		data = read_line(fd);
		if (!data)
			break ;
		add_list(&list, data);
	}
	if (list)
		data = get_data(list);
	clean_list(&list);
	return (data);
}
