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

#include "../includes/ft_printf.h"

static	void	reverse(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int	ft_base(char *result, size_t n, const char *base)
{
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	i = 0;
	if (n == 0)
	{
		result[i++] = base[0];
		result[i] = '\0';
	}
	while (n != 0)
	{
		result[i++] = base[n % base_len];
		n /= base_len;
	}
	result[i] = '\0';
	reverse(result, i);
	return (ft_strlen(result));
}

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
