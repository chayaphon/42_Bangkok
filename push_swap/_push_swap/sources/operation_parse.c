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

int	isnum_int(char *str)
{
	int		i;
	int		len;
	char	*max_int;

	max_int = "2147483647";
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			max_int = "2147483648";
	i = -1;
	len = ft_strlen(str);
	if (len > 10)
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) || (len == 10 && str[i] > max_int[i]))
			return (0);
	}
	return (1);
}

int	is_duplicate(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[++j])
			if (i != j && ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
	}
	return (0);
}

int	validate_input(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isnum_int(str[i]))
			return (0);
		i++;
	}
	if (is_duplicate(str))
		return (0);
	return (1);
}

int	ft_parser(int argc, char ***argv)
{
	if (argc == 1 || (argc == 2 && !(*argv)[1][0]))
		return (0);
	else if (argc == 2)
		*argv = ft_split((*argv)[1], ' ');
	else if (argc > 2)
		(*argv)++;
	if (!validate_input(*argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
