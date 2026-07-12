/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 00:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/07/12 15:22:58 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_str(char *toput)
{
	write(1, toput, ft_strlen(toput));
}

void	ft_put_numeric_related(long int num, double dbl, char arg)
{
	if (arg == 'i')
		ft_putnbr(num);
	if (arg == 'd')
		ft_putnbr_double(dbl, 10);
	else if (arg == 'u')
		ft_putnbr((unsigned int)num);
}

void	ft_format(char c, va_list args)
{
	if (c == 's')
		ft_put_str(va_arg(args, char *));
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'd' || c == 'i' || c == 'u')
		ft_put_numeric_related(va_arg(args, long int),
			va_arg(args, double), c);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *));
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(*format, args);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}
