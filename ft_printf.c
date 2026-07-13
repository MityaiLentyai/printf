/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:21:54 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/13 18:14:28 by dzzayats         ###   ########.fr       */
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

static int	print_arg(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (spec == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (spec == 'x')
		return (ft_puthex_lower(va_arg(ap, unsigned int)));
	if (spec == 'X')
		return (ft_puthex_upper(va_arg(ap, unsigned int)));
	if (spec == 'p')
		return (ft_putpointer(va_arg(ap, void *)));
	if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	arguments;
	int		counter;
	int		i;

	va_start(arguments, string);
	counter = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			counter += print_arg(string[i], arguments);
		}
		else
		{
			counter += ft_putchar(string[i]);
		}
		i++;
	}
	va_end(arguments);
	return (counter);
}

// #include <stdio.h>

// int	main(void)
// {
//         int aaa = 5;
//         int *ptrAAA = &aaa;
// 	int	aa = printf("PTR: %p \n", ptrAAA);
// 	int	a = ft_printf("PTR: %p \n", ptrAAA);

// 	printf("original count:%d\nmy count:%d\n", aa, a);
// 	return (0);
// }
