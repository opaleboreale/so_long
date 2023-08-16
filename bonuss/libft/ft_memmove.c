/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:18:29 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 19:40:42 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (src > dest)
	{
		i = 0;
		while (i < (int)n)
		{
			ptrdest[i] = ptrsrc[i];
			i++;
		}
	}
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			ptrdest[i] = ptrsrc[i];
			i--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
		char	dest0[] = "1234567890";
		char	dest1[] = "1234567890";
		char	dest2[] = "1234567890";
		char	dest3[] = "1234567890";
		char	s[] = {65, 66, 67, 68, 69, 0, 45};
		char	s0[] = {0, 0 ,0 ,0 ,0 ,0 ,0 };

		printf("%s\n", (char *)ft_memmove(dest0, dest0 + 5, 5));
		printf("%s\n", (char *)memmove(dest1, dest1 + 5, 5));
		printf("===========================\n");
		printf("%s\n", (char *)ft_memmove(dest2 + 5, dest2, 5));
		printf("%s\n", (char *)memmove(dest3 + 5, dest3, 5));
		printf("===========================\n");
		printf("%s\n", (char *)ft_memmove(s0, s, 7));
		write(1, s0 + 6, 1);
		write(1, "\n", 1);
		return (0);
}
*/
