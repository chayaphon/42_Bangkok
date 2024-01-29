/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:09:47 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:09:50 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
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
		printf("%c",ft_toupper(i));
		i++;
	}
	printf("\n");
	return (0);
}*/