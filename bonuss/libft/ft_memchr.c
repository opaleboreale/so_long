/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:12:35 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 05:03:34 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sp;

	i = 0;
	sp = (unsigned char *)s;
	while (i < n)
	{
		if (*(sp + i) == (unsigned char)c)
			return (sp + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", (char *)ft_memchr("HELLO", 'E', 6));
	printf("%s\n", (char *)memchr("HELLO", 'E', 6));
	return (0);
}
*/
