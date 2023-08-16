/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:14:34 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 21:27:37 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_initializejoin(char *snew, char const *sa, char const *sb, int len)
{
	int	i;
	int	j;

	snew[len] = 0;
	i = 0;
	j = 0;
	while (sa[j])
	{
		snew[i] = sa[j];
		i++;
		j++;
	}
	j = 0;
	while (sb[j])
	{
		snew[i] = sb[j];
		i++;
		j++;
	}
	return (snew);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	ft_initializejoin(new, s1, s2, len);
	return (new);
}
/*
int	main(void)
{
	printf("%s\n", ft_strjoin("123", "456"));
	return (0);
}
*/
