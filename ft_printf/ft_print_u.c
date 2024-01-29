/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:11:00 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/03 00:11:02 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(const unsigned int u)
{
	unsigned int	nbr;
	int				len;
	int				tmp;

	len = 0;
	nbr = u;
	if (nbr / 10 != 0)
	{
		tmp = ft_print_u(nbr / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_print_c(nbr % 10 + '0') == -1)
		return (-1);
	len++;
	return (len);
}

/*
#include <stdio.h>
int	main(void)
{
	int a;

	//a = 123456789;
	a = -123456789;
	printf("\tlen:%d", ft_print_u(a));
	printf("\n");
	printf("\tlen:%d", printf("%u", a));
	printf("\n");
	return (0);
}*/