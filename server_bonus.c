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

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	received_char = 0;
	static int	current_bit = 7;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		received_char = 0;
		current_bit = 7;
	}
	if (signum == SIGUSR1)
		received_char |= (1 << current_bit);
	current_bit--;
	if (kill(client_pid, SIGUSR1) == -1)
		write(2, "Error\n", 6);
	if (current_bit < 0)
	{
		if (received_char == '\0')
		{
			write(1, "\n", 1);
			if (kill(client_pid, SIGUSR2) == -1)
				write(2, "Error\n", 6);
		}
		else
			write(1, &received_char, 1);
		received_char = 0;
		current_bit = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	write(1, "Server PID = ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
