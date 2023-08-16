/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:21:02 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/12 13:58:29 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*ptr++ = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}
/*
int	main(void)
{
	int	buffer0[10];
	int	buffer1[10];
	int i = 0;

	ft_memset(buffer0, 5, sizeof(int) * 3);
	//memset(buffer1, 5, sizeof(int) * 3);
	while (i < 10)
	{
		printf("%d\n", buffer0[i]);
		i++;
	}
	printf("===============================\n");
	i = 0;
	while (i < 10)
	{
		printf("%d\n", buffer1[i]);
		i++;
	}
	char	buf0[11] = "0123456789";
	//char	buf1[10];

	ft_memset(buf0, 'A', 5);
	printf("%s\n", buf0);
	return (0);
}
*/
