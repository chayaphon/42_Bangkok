/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:20:42 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/02 23:20:45 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_d(const int d)
{
	unsigned int	nbr;
	int				len;
	int				tmp;

	len = 0;
	if (d < 0)
	{
		if (ft_print_c('-') == -1)
			return (-1);
		nbr = d * -1;
		len++;
	}
	else
		nbr = d;
	if (nbr / 10 != 0)
	{
		tmp = ft_print_d(nbr / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_print_c(nbr % 10 + '0') == -1)
		return (-1);
	len++;
	return (len);
}

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
