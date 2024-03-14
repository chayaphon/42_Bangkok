/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:31:02 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/13 20:31:04 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>

void	signal_handler(int sigsent, siginfo_t *info, void *context)
{
	static unsigned char	buffer;
	static int				i;

	(void) context;
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
	if (sigsent == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sigsent == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("Welcome to Minitalk Server! \nServer ID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
