/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:54:44 by ael-mans          #+#    #+#             */
/*   Updated: 2024/12/24 11:41:14 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_checker(const char *formats, va_list args)
{
	int	count;

	count = 0;
	if (*formats == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*formats == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*formats == 'x' || *formats == 'X')
		count = ft_put_hex(va_arg(args, unsigned), *formats);
	else if (*formats == 'd' || *formats == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (*formats == 'u')
		count = ft_putnbr(va_arg(args, unsigned));
	else if (*formats == 'p')
		count = ft_put_ptr(va_arg(args, void *), *formats);
	else if (*formats == '%')
		count = ft_putchar('%');
	else
	{
		count = ft_putchar('%');
		count += ft_putchar(*formats);
	}
	return (count);
}

int	ft_printf(const char *formats, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!formats)
		return (-1);
	va_start(args, formats);
	while (*formats)
	{
		if (*formats == '%')
		{
			formats++;
			if (*formats == '\0')
				return (va_end(args), (-1));
			count += format_checker(formats, args);
		}
		else
			count += ft_putchar(*formats);
		formats++;
	}
	va_end(args);
	if (catch_err(0) == -1)
		return (-1);
	return (count);
}
