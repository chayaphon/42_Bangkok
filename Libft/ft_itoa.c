/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:31:23 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:31:51 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_numlen(long nb)
{
	int	num_len;

	num_len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		num_len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		num_len++;
	}
	return (++num_len);
}

char	*ft_itoa(int n)
{
	size_t	num_len;
	size_t	i;
	long	nb;
	char	*res;

	nb = n;
	num_len = str_numlen(nb);
	res = malloc(sizeof(char) * (num_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		nb = -nb;
	while (i < num_len)
	{
		res[num_len - 1 - i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		*res = '-';
	res[num_len] = '\0';
	return (res);
}

/*
#include<stdio.h>
int	main(void)
{
	printf("%s\n",ft_itoa(-2147483648));
	return (0);
}*/