/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:21:54 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/11 00:46:49 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int max(int num_args, ...);

int main ()
{
       int max_num =  max (4, 10,12, 14,16, 25, 3,120);
        printf("max_num %d\n", max_num);
}

int max(int num_args, ...)
{
        va_list args;
        va_start(args, num_args);

        int max = 0;
        int i = 0;
        while (i < num_args)
        {
                int x = va_arg(args, int);
                if (i == 0) max = x;
                else if (x > max) max = x;
                i++;
        } 
        va_end(args);
        
        return (max);
}