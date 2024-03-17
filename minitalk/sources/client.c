/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csorntha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:30:33 by csorntha          #+#    #+#             */
/*   Updated: 2024/03/13 20:30:40 by csorntha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>

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

void	sig_send_message(int pid, char *str, size_t len)
{
	size_t	i;
	int		pos;

	i = 0;
	while (i < len)
	{
		pos = 7;
		while (pos >= 0)
		{
			if (str[i] & (1 << pos))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pos--;
			usleep(100);
		}
		i++;
	}
	sig_send_newline(pid);
	ft_printf("%d characters has been send\n", i);
}

int	main(int argc, char	**argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		ft_printf("Please input server pid and one message argument.\n");
	else
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		sig_send_message(pid, str, ft_strlen(str));
	}
}
