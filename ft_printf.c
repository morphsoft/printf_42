/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 00:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/07/06 00:00:00 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char_related(char *toput, char arg)
{
	if (arg == 'c')
		write(1, toput, 1);
	else if (arg == 's')
		write(1, toput, ft_strlen(toput));
}

void	ft_put_numeric_related(long int num, double dbl, char arg)
{
	if (arg == 'i')
		ft_putnbr(num);
	if (arg == 'd')
		ft_putnbr_double(dbl);
	else if (arg == 'u')
		ft_putnbr_unsigned((unsigned int)num);
}

void	ft_format(char c, va_list args)
{
	if (c == 'c' || c == 's')
		ft_put_char_related((char *)&(va_arg(args, int)), 'c');
	else if (c == 'd' || c == 'i' || c == 'u')
		ft_put_numeric_related(va_arg(args, long int),
			va_arg(args, double), c);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *));
	else if (c == '%')
		ft_putchar('%');
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
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (0);
}