/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:44:06 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/29 11:55:13 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_ready;

void	acknowledge_signal(int signum)
{
	g_ready = true;
	(void)signum;
}

void	transmit_char(int pid, char c)
{
	int	i;
	int	error;

	i = 7;
	while (i >= 0)
	{
		g_ready = false;
		if (c & (1 << i))
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		i--;
		if (error == -1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (!g_ready)
			;
		usleep(150);
	}
}

void	send_message(int pid, const char *message)
{
	while (*message)
		transmit_char(pid, *message++);
	transmit_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	long	pid;

	if (argc == 3 && ft_isdigit(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, acknowledge_signal);
		send_message(pid, argv[2]);
	}
	else
		write(2, "Invalid input\n", 14);
	return (0);
}
