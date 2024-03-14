/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:31:22 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/13 20:31:25 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("1");
	if (sig == SIGUSR2)
		ft_printf("0");
}

void	sig_send_newline(int pid)
{
	int	pos;

	pos = 7;
	while (pos >= 0)
	{
		if ('\n' & (1 << pos))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pos--;
		usleep(100);
	}
}

void	sig_send(int pid, char *str, size_t len)
{
	size_t	i;
	int		pos;

	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	i = 0;
	while (i <= len)
	{
		pos = 7;
		while (pos >= 0)
		{
			if (str[i] & (1 << pos))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			pos--;
			usleep(100);
		}
		i++;
	}
	sig_send_newline(pid);
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		ft_printf("Please input server pid and message.\n");
	else
	{
		pid = atoi(argv[1]);
		str = argv[2];
		sig_send(pid, str, ft_strlen(str));
	}
	return (0);
}
