/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:30:48 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/13 22:13:30 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>

void	signal_handler(int sigsent)
{
	static unsigned char	buffer;
	static int				i;

	buffer |= (sigsent == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buffer);
		buffer = 0;
		i = 0;
	}
	else
		buffer <<= 1;
}

int	main(void)
{
	ft_printf("Welcome to Minitalk Server! \nServer ID : %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
