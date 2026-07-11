/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:21:54 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/11 09:16:39 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static  int     helper_func(const char f, va_list arg)
{
        int     len;
        
        len = 0;
	if (f == '%')
		len = ft_putchar('%');
	else if (f == 'c')
		len = ft_putchar(va_arg(arg, int));
        return (len);
}

int my_printf(const char *format, ...)
{
        va_list args;
        int     input_chars;
        int     i;
        
        input_chars = 0;
        i = 0;
        if (!format)
                return (-1);
        va_start (args,format);
        while (format[i])
        {
                if (format[i] != 0)
                {
                        
                }
                i++;
        }
        

        va_end (args);
        return (input_chars);
}
        

int main()
{
        my_printf("%c", 'c');
        
}

// #include <stdio.h>
// #include <stdarg.h>

// void mini_printf(const char *format, ...) {
//     va_list args;
//     va_start(args, format);

//     for (int i = 0; format[i] != '\0'; i++) {
//         // Check for the %c placeholder
//         if (format[i] == '%' && format[i + 1] == 'c') {
//             // Retrieve as int due to default argument promotion
//             char c = (char)va_arg(args, int); 
//             putchar(c);
//             i++; // Skip the 'c' character
//         } else {
//             putchar(format[i]); // Print regular characters
//         }
//     }

//     va_end(args);
// }

// int main() {
//     mini_printf("Hello %c%c%c\n", 'A', 'B', '!');
//     return 0;
// }
