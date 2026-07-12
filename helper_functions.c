/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:53:10 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/11 08:59:30 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
        return count;
}