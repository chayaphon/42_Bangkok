/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:12:47 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/02 23:12:49 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(const char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[len])
	{
		if (write (1, &s[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

/*
#include <stdio.h>
int	main(void)
{
	char *str;

	//str = NULL;
	str = "Hello BODY!";
	printf("\tlen:%d", ft_print_s(str));
	printf("\n");
	printf("\tlen:%d", printf("%s", str));
	printf("\n");
}*/