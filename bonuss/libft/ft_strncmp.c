/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:50:10 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 04:44:08 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (*ps1 == 0)
		return (-*s2);
	if (*ps2 == 0)
		return (*ps1);
	while (n > 0 && *ps1++ == *ps2++)
		n--;
	return (*--ps1 - *--ps2);
}
/*
int	main(void)
{
	printf("%d\n", ft_strncmp("test\0", "test\200", 5));
	printf("%d\n", strncmp("test\0", "test\200", 5));
	return (0);
}
*/
