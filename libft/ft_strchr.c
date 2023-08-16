/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:32:02 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/12 15:25:20 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return ((char *)--s);
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", ft_strchr("HELLO", 'L'));
	printf("%s\n", strchr("HELLO", 'L'));
	return (0);
}
*/
