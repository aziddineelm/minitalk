/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:44:54 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/28 18:04:26 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

void	handle_char_completion(int client_pid, char received_char);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	acknowledge(int signum);
void	signal_acknowledge(int signum, siginfo_t *info, void *context);
void	transmit_char(int pid, char c);
void	sender(int pid, const char *message);
void	last_send(int pid);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_isdigit(char *str);
long	ft_atoi(const char *str);
int		ft_strlen(const char *str);

#endif
