/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:56:46 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/15 01:56:48 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_clear_content(void *content)
{
	free (content);
}

void	ft_free_array(char **str)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
	}
}

t_list	*ft_create_node(int index_val, int content_val)
{
	int		*index;
	int		*content;
	t_list	*new_lst;

	index = malloc(sizeof(int));
	content = malloc(sizeof(int));
	if (!index || !content)
	{
		free(index);
		free(content);
		return (0);
	}
	*index = index_val;
	*content = content_val;
	new_lst = ft_lstnew(index, content);
	if (!new_lst)
	{
		free(index);
		free(content);
		return (0);
	}
	return (new_lst);
}

int	ft_initial_stack(t_list **node, char **val)
{
	t_list	*new_lst;
	int		i;

	i = -1;
	while (val[++i])
	{
		new_lst = ft_create_node(0, ft_atoi(val[i]));
		if (!new_lst)
			return (0);
		ft_lstadd_back(node, new_lst);
	}
	if (!ft_index_sorting(*node, ft_lstsize(*node)))
		return (0);
	return (1);
}

int	*ft_gerate_midpoint(t_list *node)
{
	int	*mid_point_array;
	int	node_size;
	int	mid_point;
	int	i;

	i = 0;
	mid_point = 0;
	node_size = ft_lstsize(node);
	mid_point_array = (int *)malloc(sizeof(int) * node_size);
	if (!mid_point_array)
		return (NULL);
	ft_memset(mid_point_array, 0, sizeof(int) * node_size);
	while (mid_point < node_size - 1)
	{
		if ((node_size - mid_point) % 2 == 0)
			mid_point = ((node_size - mid_point) / 2) + mid_point;
		else
			mid_point = (((node_size - mid_point) + 1) / 2) + mid_point;
		mid_point_array[i++] = mid_point;
	}
	return (mid_point_array);
}
