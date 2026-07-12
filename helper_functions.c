/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:53:10 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/12 21:29:20 by dzzayats         ###   ########.fr       */
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
	char		temp;
	const char	minus = '-';

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		n *= -1;
		return (write(1, &minus, 1));
	}
	temp = ((n % 10) + '0');
	if ((n / 10) > 0)
		ft_putnbr(n / 10);
	return (write(1, &temp, 1));
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
