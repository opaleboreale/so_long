/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:57:28 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/22 09:35:48 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Our goal here is to implement a function which will enable us to read 
 *	a line from a file descriptor passed as argument to the function.
 *	
 *	By calling this function inside a loop, we will be able to display the
 *	content of an entire line, one line after the other. Very useful.
 *
 *	RETURN VALUE
 *	The line that was read
 *	But if there is nothing else to read or if an err occurs, then return NULL
 *
 *	The returned line must include the terminating \n except if the EOF has 
 *	been reached.
 *
 *
 *
 *	THE READ FUNCTION
 *	int read(fd, buf, nb_bytes)
 *	Read nb_bytes of data into the file descriptor fd and place them into the
 *	zone pointed to by buf. As a consequence, this zone should be at least
 *	of size nb_bytes.
 */

#include "get_next_line.h"

int	is_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-2);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_extendline(char *line, size_t newsize, char *buffer)
{
	char	*newline;

	newline = ft_calloc(newsize, sizeof(char));
	if (!newline)
		return (0);
	if (line)
		ft_memmove(newline, line, ft_strlen(line));
	ft_strlcat(newline, buffer, newsize);
	if (line)
		free(line);
	return (newline);
}

char	*buffer_not_empty(char *line, char *buffer)
{
	int		i;
	char	tmp;
	size_t	size;

	i = is_line(buffer);
	if (i >= 0)
	{
		tmp = buffer[i + 1];
		buffer[i + 1] = 0;
		size = ft_strlen(line) + ft_strlen(buffer) + 1;
		line = ft_extendline(line, size, buffer);
		buffer[i + 1] = tmp;
		size = ft_strlen(buffer + i + 1) + 1;
		ft_memmove(buffer, buffer + i + 1, size);
		ft_bzero(buffer + size + 1, BUFFER_SIZE - size + 1);
		return (line);
	}
	size = ft_strlen(line) + ft_strlen(buffer) + 1;
	if (*buffer)
	{
		line = ft_extendline(line, size, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*ft_searchline(int fd, char *line, char *buffer)
{
	int		nb_bytes;
	size_t	size;

	nb_bytes = BUFFER_SIZE;
	while (nb_bytes == BUFFER_SIZE && is_line(buffer) == -1)
	{
		size = ft_strlen(line) + ft_strlen(buffer) + 1;
		line = ft_extendline(line, size, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
		if (!line)
			return (0);
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (*buffer)
		line = buffer_not_empty(line, buffer);
	if (is_line(line) >= 0)
		return (line);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i == BUFFER_SIZE && is_line(buffer) == -1)
	{
		line = ft_searchline(fd, line, buffer);
		if (!line)
			return (0);
	}
	if (i == -1 && line)
		free(line);
	if (i == -1)
		return (0);
	if (*buffer && i > 0)
		line = buffer_not_empty(line, buffer);
	return (line);
}
