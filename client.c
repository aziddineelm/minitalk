/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:44:06 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/28 18:04:40 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "talk.h"

void	send_char(int pid, char c)
{
	int	i;
	int	error;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		i--;
		usleep(600);
		if (error == -1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		pause();
		usleep(150);
	}
}

void	bits_to_signals(int pid, char *str)
{
	int	y;

	y = 0;
	while (str[y])
	{
		send_char(pid, str[y]);
		y++;
	}
	send_char(pid, '\0');
}

void	confirmation_handler(int signum)
{
	(void)signum;
}

int	main(int argc, char **argv)
{
	long	pid;

	if (argc == 3 && ft_isdigit(argv[1][0]))
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, confirmation_handler);
		bits_to_signals(pid, argv[2]);
	}
	else
		write(2, "Invalid input\n", 14);
	return (0);
}
