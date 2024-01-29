/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:16:07 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:16:14 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	overflow_return(int neg)
{
	if (neg == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		neg;
	int		i;
	long	result;

	neg = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result < 0)
			return (overflow_return(neg));
	}
	return (result * neg);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main() 
{
	//char str[] = "9223372036854775807";
	char str[] = "+0000000000000000000000000123";
	int result1 = atoi(str);
	int result2 = ft_atoi(str);
	printf("result1 : %d\n", result1);
	printf("result2 : %d\n", result2);
	return (0);
}*/