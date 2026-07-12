/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:53:10 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/12 03:19:21 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c)
{
        write(1,&c, 1);
}

void    ft_putstr(char *s)
{
        int count;

        count = 0;
        while (*s && *s)
        {
                ft_putchar(*s++);
        }
}
// d = 123, 

void	ft_putnbr(int n)
{
	int			temp;
	const char	minus = '-';

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, &minus, 1);
	}
	temp = (char)((n % 10) + '0');
	if ((n / 10) > 0)
		ft_putnbr(n / 10);
	write(1, &temp, 1);
}