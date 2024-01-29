/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:11:26 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:11:36 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*
#include<stdio.h>
int	main(void)
{
	int	i;

	i = 32;
	while (i <= 127)
	{
		printf("%c",ft_tolower(i));
		i++;
	}
	printf("\n");
	return (0);
}*/