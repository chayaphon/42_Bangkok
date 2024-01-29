/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:56:50 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/02 20:57:39 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(const size_t p)
{
	char	*str;
	int		len;

	if (!p)
	{
		if (ft_print_s("0x0") == -1)
			return (-1);
		return (3);
	}
	str = malloc((sizeof(size_t) * CHAR_BIT) + 1);
	if (str == NULL)
		return (-1);
	len = ft_base(str, p, "0123456789abcdef");
	if (ft_print_s("0x") == -1)
	{
		free(str);
		return (-1);
	}
	if (ft_print_s(str) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len + 2);
}

/*
#include <stdio.h>
int main(void)
{
	size_t a;

	a = 11552;
	printf("\tlen:%d", ft_print_p((size_t)&a));
	printf("\n");
	printf("\tlen:%d", printf("%p", &a));
	printf("\n");
}*/