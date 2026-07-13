/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:30:07 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/12 21:30:07 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	return (ft_puthex_base(n, "0123456789abcdef"));
}

int	ft_puthex_upper(unsigned int n)
{
	return (ft_puthex_base(n, "0123456789ABCDEF"));
}

int	ft_putpointer(void *ptr)
{
	uintptr_t	u_addres;
	char		*base;
	int			count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	u_addres = (uintptr_t) ptr;
	base = "0123456789abcdef";
	count += ft_puthex_pointer(u_addres, base);
	return (count);
}

int	ft_puthex_pointer(uintptr_t n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_pointer(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}
