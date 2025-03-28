/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:00:17 by ael-mans          #+#    #+#             */
/*   Updated: 2024/12/24 11:41:06 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char c)
{
	int		count;
	char	*base;

	count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_put_hex((n / 16), c);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_put_ptr(void *ptr, char c)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = ft_putstr("(nil)");
		return (count);
	}
	count = ft_putstr("0x");
	count += ft_put_hex((unsigned long)ptr, c);
	return (count);
}
