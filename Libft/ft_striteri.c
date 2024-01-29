/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:39:06 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:39:29 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*
#include <stdio.h>
void cap_even_ascletter(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
    {
        *c -= ('a' - 'A'); // capitalize the character
    }
}

int main()
{
    char str[] = "abcdef"; // Using a char array so it's mutable
    ft_striteri(str, cap_even_ascletter);
    printf("%s\n", str); // Should print "AbCdEf"
    return 0;
}*/