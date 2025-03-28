/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:44:06 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/28 17:44:08 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char_bit(int pid, char c)
{
	int	counter;
	int	error;

	counter = 7;
	while (counter >= 0)
	{
		if ((c >> counter) & 1)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		usleep(100);
		counter--;
		if (error == -1)
		{
			ft_printf("error");
			exit(1);
		}
	}
}

static void	send_message(int pid, char *str)
{
	while (*str)
	{
		send_char_bit(pid, *str);
		str++;
	}
}

static void	send_null_terminator(int pid)
{
	int	counter;
	int	error;

	counter = 7;
	while (counter >= 0)
	{
		error = kill(pid, SIGUSR2);
		usleep(100);
		counter--;
		if (error == -1)
		{
			ft_printf("error");
			exit(1);
		}
	}
}

static void	acknowledge(int signal)
{
	(void)signal;
	ft_printf("message received");
}

int	main(int ac, char **av)
{
	long	pid;

	signal(SIGUSR1, acknowledge);
	if (ac != 3)
	{
		ft_printf("error: provide 2 arguments only!!!");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (ft_strlen(av[1]) > 7 || pid <= 0 || pid > 4194304)
	{
		ft_printf("The provided PID is outside the valid range!");
		exit(1);
	}
	send_message(pid, av[2]);
	send_null_terminator(pid);
	return (0);
}
