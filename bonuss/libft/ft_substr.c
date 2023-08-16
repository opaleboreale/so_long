/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:51:26 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 03:34:31 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	if (ft_strlen(s) <= start)
		size = 0;
	else if (len < ft_strlen(s + start))
		size = len;
	else
		size = ft_strlen(s + start);
	substr = malloc(sizeof(char) * size + 1);
	if (!substr)
		return (0);
	i = 0;
	while (i < size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
/*
int	main(void)
{
	//printf("%s\n", ft_substr("HELLO", 0, 5));
	printf("%s\n", ft_substr("1", 42, 1));
	return (0);
}
*/
