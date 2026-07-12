/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:21:54 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/12 22:57:36 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

// void type_converter(char c,va_list argument,const char *string)
// {
//         va_list args_copy;
//         va_copy(args_copy,argument);

//         if (c == '%')
//         {
//                 string++;
//                 if (*string == 'c')
//                         ft_putchar((char)va_arg(args_copy,int));
//         }
// }

int	ft_printf(const char *string, ...)
{
	va_list			arguments;
	int				i;
	int				counter;
	char			c;
	char			*s;
	int				d;
	unsigned int	u;
        unsigned int    x;
        unsigned int    X;
        
	va_start(arguments, string);
	counter = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1] == 'c')
		{
			c = va_arg(arguments, int);
			counter += ft_putchar(c);
			i++;
		}
		else if (string[i] == '%' && string[i + 1] == 's')
		{
			s = va_arg(arguments, char *);
			counter += ft_putstr(s);
			i++;
		}
		else if (string[i] == '%' && ((string[i + 1] == 'd') ||
					(string[i + 1] == 'i')))
		{
			d = va_arg(arguments, int);
			counter += ft_putnbr(d);
			i++;
		}
		else if (string[i] == '%' && string[i + 1] == 'u')
		{
			u = va_arg(arguments, unsigned int);
			counter += ft_putnbr_unsigned(u);
			i++;
		}
		else if (string[i] == '%' && string[i + 1] == 'x')
		{
			x = va_arg(arguments, unsigned int);
			counter += ft_puthex_lower(x);
			i++;
		}
		else if (string[i] == '%' && string[i + 1] == 'X')
		{
			X = va_arg(arguments, unsigned int);
			counter += ft_puthex_upper(X);
			i++;
		}
		else
		{
                        if (string[i] == '%' && string[i+1] == '%')
                                i++;
			ft_putchar(string[i]);
			counter++;
		}
		i++;
	}
	va_end(arguments);
	return (counter);
}

#include <stdio.h>

int	main(void)
{
	int	aa = printf("%%My cunt is %c %%%% %s%s %X\n%%", 'A', "Proper", "Bober", -5);
	int	a = ft_printf("%%My cunt is %c %%%% %s%s %X\n%%", 'A', "Proper", "Bober", -5);

	printf("original count:%d\nmy count:%d\n", aa, a);
	return (0);
}
