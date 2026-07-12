/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:20:14 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/07/12 15:29:06 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long number, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (number >= 16)
		count += ft_puthex(number / 16, format);
	count += ft_putchar_fd(base[number % 16], 1);
	return (count);
}

void	ft_putnbr(long int toprint)
{
	long int	number;

	number = toprint;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{
		number *= -1;
		toprint *= -1;
		ft_putchar_fd('-', 1);
	}
	if (number > 9)
	{
		number /= 10;
		ft_putnbr(number);
	}
	ft_putchar_fd((toprint % 10) + '0', 1);
}

void	ft_putnbr_double(double toprint, int precision)
{
	long int	number;
	double		remaining;

	if (toprint < 0)
	{
		number = (long int)(-toprint);
		ft_putchar_fd('-', 1);
	}
	else
		number = (long int)toprint;
	remaining = toprint - (double)number;
	ft_putnbr(number);
	ft_putchar_fd('.', 1);
	ft_putnbr((long int)(remaining * (10 * precision)));
}

void	ft_putptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	write(1, "0x", 2);
	ft_puthex(address, 'x');
}
