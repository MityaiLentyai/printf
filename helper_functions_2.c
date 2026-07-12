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
