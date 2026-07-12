/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:53:10 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/12 19:09:22 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putchar(char c)
{
       return (write(1,&c, 1));
}

int    ft_putstr(char *s)
{
        int count;

        count = 0;
        while (*s && *s)
        {
                ft_putchar(*s++);
                count++;
        }
        return (count);
}
// d = 123, 

int	ft_putnbr(int n)
{
	char			temp;
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
		count += ft_putnbr_unsigned(n / 10); // Accumulate recursion counts
	
	count += write(1, &temp, 1); 
	
	return (count);
}

