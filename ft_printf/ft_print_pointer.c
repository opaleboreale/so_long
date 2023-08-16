/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:26:05 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/26 15:48:05 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer_hex(unsigned long address, char *base, int *len);
int	ft_printpointer(void *p);

int	ft_printpointer_hex(unsigned long address, char *base, int *len)
{
	if (address > 15)
		ft_printpointer_hex(address / 16, base, len);
	return (*len += ft_printchar(base[address % 16]));
}

int	ft_printpointer(void *p)
{
	int				len;
	unsigned long	n;

	n = (unsigned long)p;
	len = 0;
	if (n == 0)
		return (ft_printstr("(nil)"));
	len += ft_printstr("0x");
	return (ft_printpointer_hex(n, "0123456789abcdef", &len));
}
