/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:33:48 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 05:03:02 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_lentrim(const char *s1, const char *set)
{
	int	len;
	int	i;

	len = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] && ft_ischarset(s1[i], set) == 1)
		i++;
	if (i == len + 1)
		return (0);
	while (len >= 0 && ft_ischarset(s1[len], set) == 1)
		len--;
	return (len - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	int		len;
	int		i;
	int		j;

	len = ft_lentrim(s1, set);
	strim = malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	if (!strim)
		return (0);
	while (j < len && s1[i])
	{
		while (s1[i] && ft_ischarset(s1[i], set) == 1)
			i++;
		while (s1[i] && j < len)
		{
			strim[j] = s1[i];
			i++;
			j++;
		}
	}
	strim[j] = 0;
	return (strim);
}
/*
int	main(void)
{
//	char	s1[] = "====HELL=O======";
//	char	set[] = "=";
	char	*strim;

	char	s1[] = "           ";
	char	set[] = "\t \n";
	strim = ft_strtrim(s1, set);
	//printf("%s\n", strim);
	free(strim);
	return (0);
}
*/
