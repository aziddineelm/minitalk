/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:44:42 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/28 18:05:07 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit_position = 7;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit_position = 7;
	}
	if (signum == SIGUSR1)
		c |= (1 << bit_position);
	bit_position--;
	if (kill(client_pid, SIGUSR1) == -1)
		write(2, "Error\n", 6);
	if (bit_position < 0)
	{
		if (c == 0)
			exit(0);
		write(1, &c, 1);
		c = 0;
		bit_position = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int				pid;

	pid = getpid();
	write(1, "Server PID = ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
