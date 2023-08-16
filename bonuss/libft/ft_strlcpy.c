/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:39:56 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 05:04:09 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (size <= 0)
		return (lensrc);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (lensrc);
}
/*
int	main(void)
{
	char	dst0[10];
	char	src[] = "HELLO";

	printf("%ld\n%s\n", ft_strlcpy(dst0, src, 5), dst0);
	printf("%ld\n", ft_strlen(src));
	return (0);
}
*/
