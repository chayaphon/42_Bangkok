/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:36:04 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/02 23:11:08 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_conversion(const char *str, va_list *args)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_print_c(va_arg(*args, int));
	else if (*str == 's')
		len += ft_print_s(va_arg(*args, char *));
	else if (*str == 'd' || *str == 'i')
		len += ft_print_d(va_arg(*args, int));
	else if (*str == 'u')
		len += ft_print_u(va_arg(*args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		len += ft_print_x((va_arg(*args, unsigned int)), *str);
	else if (*str == 'p')
		len += ft_print_p(va_arg(*args, unsigned long long));
	else if (*str == '%')
		len += ft_print_c('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		tmp;

	tmp = 0;
	len = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			tmp = ft_conversion(str, &args);
		}
		else
			tmp = ft_print_c(*str);
		if (tmp == -1)
			return (-1);
		len += tmp;
		str++;
	}
	va_end(args);
	return (len);
}
