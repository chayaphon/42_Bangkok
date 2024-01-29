/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:27:48 by csorntha          #+#    #+#             */
/*   Updated: 2023/12/03 00:27:50 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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

/*
#include <stdio.h>
int main()
{
    size_t number = 123456;
    char *base = "0123456789abcdef";
    char *converted = ft_base(number, base);

    if (converted != NULL)
    {
        printf("Converted number: %s\n", converted);
        free(converted);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/