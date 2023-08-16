/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:36:59 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/13 00:14:27 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (dst == 0)
		return (0);
	len = ft_strlen(dst) + ft_strlen(src);
	i = ft_strlen(dst);
	if (size <= 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= size)
		len = size + ft_strlen(src);
	while (*src && i < size - 1)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = 0;
	return (len);
}
/*
int	main(void)
{
	char	dst[10] = "coucou";
	char	src[] = "toi";

	printf("%ld\n%s\n", ft_strlcat(dst, src, 3), dst);
	return (0);
}
*/
