/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:25 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/07 23:03:20 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	buffer0[] = "HELLO";
	char	buffer1[] = "HELLO";

	//ft_bzero(buffer0, sizeof(char) * ft_strlen(buffer0));
	//bzero(buffer1, sizeof(char) * strlen(buffer1));
	printf("%s\n", buffer0);
	printf("%s\n", buffer1);
}
*/
