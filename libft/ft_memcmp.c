/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:07:30 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/12 15:13:22 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr1 == *ptr2 && --n > 0)
	{
		ptr1++;
		ptr2++;
	}
	if (*ptr1 > *ptr2)
		return (1);
	else if (*ptr1 < *ptr2)
		return (-1);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_memcmp("HELLO", "HELL", 5));
	printf("%d\n", memcmp("HELLO", "HELL", 5));
	return (0);
}
*/
