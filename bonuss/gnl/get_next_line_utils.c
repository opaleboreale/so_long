/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:40:11 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/22 09:32:10 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (dst == 0)
		return (0);
	len = ft_strlen(dst) + ft_strlen(src);
	i = ft_strlen(dst);
	if (size <= 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= size)
		len = size + ft_strlen(src);
	while (*src && i < size - 1)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = 0;
	return (len);
}

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (src > dest)
	{
		i = 0;
		while (i < (int)n)
		{
			*(ptrdest + i) = *(ptrsrc + i);
			i++;
		}
	}
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(ptrdest + i) = *(ptrsrc + i);
			i--;
		}
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*ptr++ = 0;
		i++;
	}
}
