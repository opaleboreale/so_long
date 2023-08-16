/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:00:56 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 13:01:11 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

char	*exit_1(char *tmp, char *map_str)
{
	if (tmp)
		free(tmp);
	return (map_str);
}

char	*exit_2(char *map_str, char *line)
{
	if (map_str)
		free(map_str);
	free(line);
	return (0);
}

char	*read_file(int fd, char *tmp, char *map_str, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (exit_1(tmp, map_str));
		if (map_str)
			tmp = ft_strdup(map_str);
		if (!tmp)
			return (exit_2(map_str, line));
		if (map_str)
			free(map_str);
		map_str = ft_strjoin(tmp, line);
		free(tmp);
		tmp = 0;
		if (!map_str)
			return (0);
	}
	free(line);
	return (map_str);
}

char	*get_map_str(int fd)
{
	char	*map_str;
	char	*line;
	char	*tmp;

	map_str = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	tmp = ft_strdup(line);
	if (!tmp)
	{
		free(line);
		return (0);
	}
	map_str = read_file(fd, tmp, map_str, line);
	return (map_str);
}
