/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:30:40 by csorntha          #+#    #+#             */
/*   Updated: 2023/09/03 16:30:13 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*str_split(char const *str, char c)
{
	char	*word;
	int		len_word;
	int		i;

	i = 0;
	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!str)
		return (0);
	result = (char **)malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!result)
		return (0);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			result[i] = str_split(str, c);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	result[i] = 0;
	return (result);
}

/*
#include <stdio.h>
int	main(void)
{
	int		i;
	char	**split;
	split = ft_split("helloxworldx42", 'x');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/