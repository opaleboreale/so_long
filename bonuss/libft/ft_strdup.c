/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:44:33 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 02:52:07 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	todup[] = "HELLO";

	s1 = ft_strdup(todup);
	s2 = strdup("HELLO");
	printf("%s\n", s1);
	printf("%s\n", s2);
	free(s1);
	free(s2);
	return (0);
}
*/
