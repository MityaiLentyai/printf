/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:17:20 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/11 18:17:20 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_PRINTF_H
#ifdef FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>

// int     ft_printf(const char * format,...) __attribute__((format(printf,
// 			1, 2)));
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int d);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_puthex_base(unsigned int n, const char *base);
int	ft_putpointer(void *ptr);
int	ft_puthex_pointer(uintptr_t n, const char *base);

#endif
