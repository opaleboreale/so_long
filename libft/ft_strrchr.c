/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:42:29 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 05:03:47 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*sp;

	i = ft_strlen(s) - 1;
	sp = (char *)s;
	if (c == 0)
		return (sp + i + 1);
	while (i >= 0)
	{
		if (s[i--] == (char)c)
			return ((char *)(s + ++i));
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", ft_strrchr("HELLO", 'L'));
	printf("%s\n", strrchr("HELLO", 'L'));
	return (0);
}
*/
