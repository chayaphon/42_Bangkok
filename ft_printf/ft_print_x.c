/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:20:28 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/03 00:20:30 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(const unsigned int x, const char c)
{
	char	*str;
	int		len;

	if (!x)
	{
		if (ft_print_c('0') == -1)
			return (-1);
		return (1);
	}
	str = malloc(sizeof(size_t) * CHAR_BIT + 1);
	if (str == NULL)
		return (-1);
	if (c == 'X')
		len = ft_base(str, x, "0123456789ABCDEF");
	else
		len = ft_base(str, x, "0123456789abcdef");
	if (ft_print_s(str) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

/*
#include <stdio.h>
int main(void)
{
	unsigned int a;

	a = 4294967295;
	printf("\tlen:%d", ft_print_x(a, 'x'));
	printf("\n");
	printf("\tlen:%d", ft_print_x(a, 'X'));
	printf("\n");
	printf("\tlen:%d", printf("%x", a));
	printf("\n");
	printf("\tlen:%d", printf("%X", a));
	printf("\n");
}*/