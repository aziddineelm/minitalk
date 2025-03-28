/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:37:26 by ael-mans          #+#    #+#             */
/*   Updated: 2024/12/23 14:47:45 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	catch_err(int n)
{
	static int	i;

	if (n == -1)
		i = -1;
	if (i == -1)
		return (i);
	return (1);
}

int	ft_putchar(char c)
{
	return (catch_err(write(1, &c, 1)));
}
