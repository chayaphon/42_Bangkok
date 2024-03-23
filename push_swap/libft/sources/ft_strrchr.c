/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:12:48 by csorntha          #+#    #+#             */
/*   Updated: 2023/08/26 14:12:56 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	uc;

	uc = c;
	len = ft_strlen(s);
	if (s[len] == uc)
		return ((char *)s + len);
	while (len--)
	{
		if (s[len] == uc)
			return ((char *)s + len);
	}
	return (0);
}
