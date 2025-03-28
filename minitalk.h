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
# include <stdbool.h>
# include <stdlib.h>
# include "Printf/ft_printf.h"

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putnbr(int n);

#endif
