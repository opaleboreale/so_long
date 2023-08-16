/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:11:46 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/08 18:25:56 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
			nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
				sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb *= 10;
		nb += *nptr - '0';
		nptr++;
	}
	return (sign * nb);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("   -33"));
	printf("%d\n", atoi("   -33"));
	return (0);
}
*/
