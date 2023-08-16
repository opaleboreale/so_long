/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:24:40 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/26 15:50:43 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdeci(int n, int *len);
int	ft_printud(unsigned int n, int *len);
int	ft_printnbr_hex(unsigned int n, char *base, int *len);

int	ft_printdeci(int n, int *len)
{
	long int	nb;

	nb = (n > 0) * n - (n < 0) * (long int)n;
	if (n < 0)
		*len += ft_printchar('-');
	if (nb > 9)
		ft_printdeci(nb / 10, len);
	return (*len += ft_printchar(nb % 10 + '0'));
}

int	ft_printud(unsigned int n, int *len)
{
	if (n > 9)
		ft_printud(n / 10, len);
	return (*len += ft_printchar(n % 10 + '0'));
}

int	ft_printnbr_hex(unsigned int n, char *base, int *len)
{
	if (n > 15)
		ft_printnbr_hex(n / 16, base, len);
	return (*len += ft_printchar(base[n % 16]));
}
