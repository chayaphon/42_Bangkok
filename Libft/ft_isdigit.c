/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:03:57 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:04:12 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    printf("normal fucntion : %d\n",isdigit(argv[1][0]));
    printf("ft fucntion : %d\n",ft_isdigit(argv[1][0]));
}*/