/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:03:45 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 02:36:37 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	i = 0;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	while (i < n)
	{
		*ptrdest++ = *ptrsrc++;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest0[10];
	char	dest1[10];
	char	src[] = "HELLO";

	printf("%s\n", (char *)ft_memcpy(dest0, src, 100));
	printf("%s\n", (char *)memcpy(dest1, src, 100));
	return (0);
}
*/
