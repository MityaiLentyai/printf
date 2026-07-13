/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:53:10 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/14 00:02:59 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s && *s)
	{
		ft_putchar(*s++);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	temp;
	int		count;

	count = 0;
	temp = (n % 10) + '0';
	if ((n / 10) > 0)
		count += ft_putnbr_unsigned(n / 10);
	count += write(1, &temp, 1);
	return (count);
}

int	ft_puthex_base(unsigned int n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_base(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}
