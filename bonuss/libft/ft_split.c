/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:34:59 by mferracc          #+#    #+#             */
/*   Updated: 2023/02/19 01:47:18 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwd(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_lenwd(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
			len++;
	return (len);
}

char	*ft_word(char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_lenwd(s, c);
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

int	ft_initialize_split(char **buffer, char const *s, char c, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < count && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			buffer[j] = ft_word((char *)s + i, c);
			if (buffer[j] == 0)
				return (1);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	buffer[j] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		i;
	int		count;

	i = 0;
	count = ft_countwd(s, c);
	buffer = malloc(sizeof(char *) * (count + 1));
	if (!buffer)
		return (0);
	if (ft_initialize_split(buffer, s, c, count) == 1)
	{
		while (buffer[i])
		{
			free(buffer[i]);
			i++;
		}
		free(buffer);
		return (0);
	}
	return (buffer);
}
/*
int	main(void)
{
	char	**buf;
	int	i;

	buf = ft_split("TVYVU.UUBI.UHUGT.UYU.IUI", '.');
	i = 0;
	while (buf[i] != 0)
	{
		printf("%s\n", buf[i]);
		free(buf[i]);
		i++;
	}
	free(buf[i]);
	free(buf);
	return (0);
}
*/
