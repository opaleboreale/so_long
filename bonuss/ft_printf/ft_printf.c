/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:16:54 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/26 15:47:04 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlenght(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(ap, int));
	if (c == 's')
		len = ft_printstr(va_arg(ap, char *));
	if (c == 'p')
		len = ft_printpointer(va_arg(ap, void *));
	if (c == 'd')
		ft_printdeci(va_arg(ap, int), &len);
	if (c == 'i')
		ft_printdeci(va_arg(ap, int), &len);
	if (c == 'u')
		ft_printud(va_arg(ap, unsigned long), &len);
	if (c == 'x')
		ft_printnbr_hex(va_arg(ap, int), "0123456789abcdef", &len);
	if (c == 'X')
		ft_printnbr_hex(va_arg(ap, int), "0123456789ABCDEF", &len);
	if (c == '%')
		len = ft_printchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		sumchar;
	int		i;

	va_start(ap, s);
	sumchar = 0;
	i = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == '%')
		{
			sumchar += ft_printlenght(ap, s[i + 1]);
			i++;
		}
		else
			sumchar += ft_printchar(s[i]);
		i++;
	}
	va_end(ap);
	return (sumchar);
}
