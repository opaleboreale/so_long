/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:26:30 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/17 07:14:59 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb == 0 || size == 0)
	{
		buffer = malloc(0);
		return (buffer);
	}
	if (size > SIZE_MAX / nmemb)
		return (0);
	buffer = malloc(size * nmemb);
	if (!buffer)
		return (0);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
/*
#include <stdint.h>
#include <stdio.h>
int	main(void)
{
	char	*tab;
	//char	*array;
	//size_t	lim = SIZE_MAX;

	//tab = (char *)ft_calloc(5, sizeof(char));
	tab = (char *)ft_calloc(SIZE_MAX, 1);
	if (tab == 0)
		printf("error\n");
	printf("%p\n", tab);
	free(tab);
	//array = calloc(lim, 1);
	//printf("===Real=CALLOC===\n");
	//printf("%s\n", array);
	//free(array);
	return (0);
}
*/
