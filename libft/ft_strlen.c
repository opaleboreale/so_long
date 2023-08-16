/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:15:50 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/07 21:20:35 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
			len++;
	return (len);
}
/*
int	main(void)
{
	printf("%ld\n", ft_strlen("Salut"));
	printf("%ld\n", strlen("Salut"));
	return (0);
}
*/
