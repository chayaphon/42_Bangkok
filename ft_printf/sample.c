/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:47:32 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/03 12:50:15 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int	main(void)
{
	char	*a;

	a = NULL;
	printf("\t len:%d\n", ft_printf("%c %s %d %u %x %p", 'A', "Hello", -521, -124, 15, a));
	printf("\t len:%d\n", printf("%c %s %d %u %x %p", 'A', "Hello", -521, -124, 15, a));
}
