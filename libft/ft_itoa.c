/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:37:38 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 19:58:46 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_len(long int nb, int n)
{
	long int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	if (n < 0)
		return (++len);
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	len;
	long int	nb;

	nb = n;
	if (n < 0)
		nb = -nb;
	len = ft_len(nb, n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	len--;
	while (len >= 0)
	{
		str[len] = '0' + nb % 10;
		nb /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
