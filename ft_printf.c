/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:21:54 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/12 03:21:25 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
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

void	mini_printf(const char *string, ...)
{
	va_list	arguments;
	int		i;
	char	c;
	char	*s;
        int     d;

	va_start(arguments, string);
	i = 0;
	while (string[i])
	{
                if (string[i] == '%' && string[i + 1] == 'c')
		{
                        c = va_arg(arguments, int);
			ft_putchar(c); 
			i++;
		}
		else if (string[i] == '%' && string[i + 1] == 's')
		{
			s = va_arg(arguments, char *);
			ft_putstr(s);
			i++;
		}
		else if (string[i] == '%' && string[i + 1] == 'd')
		{
			d = va_arg(arguments, int);
			ft_putnbr(d);
			i++;
		}

		else ft_putchar(string[i]);
		i++;
	}
	va_end(arguments);
}

int	main(void)
{
	mini_printf("My cunt is %c %s%s %d\n", 'A',"Proper", "Bober", 123);
	return (0);
}
