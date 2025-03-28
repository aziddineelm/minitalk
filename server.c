/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:44:42 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/28 17:44:43 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int signal, siginfo_t *info, void *none)
{
	static int	bit_count;
	static char	current_char;
	static int	current_pid;

	(void)none;
	if (current_pid != info->si_pid)
	{
		bit_count = 0;
		current_char = 0;
		current_pid = info->si_pid;
	}
	current_char = (current_char << 1) | (signal == SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == 0)
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
