/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:15:13 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 15:31:18 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	good_extension(t_game *game, char *berfile)
{
	int	i;

	i = ft_strlen(berfile) - 4;
	if (ft_strncmp(berfile + i, ".ber", 4) != 0)
		exit_game(game, "Invalid file\n");
	return (0);
}

t_map	*get_dim(char *s, t_map *map)
{
	int	i;

	map->width = 0;
	map->height = 1;
	while (s[map->width] && s[map->width] != '\n')
		(map->width)++;
	i = map->width;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == 0)
			map->height++;
		i++;
	}
	if (map->width == 0 || map->height == 0)
		return (0);
	return (map);
}

int	check_if_rectangle(char *s, t_map *map)
{
	unsigned long int	i;
	unsigned long int	len;

	i = 0;
	while (i < ft_strlen(s) && s[i])
	{
		len = 0;
		while (i < ft_strlen(s) && s[i] != '\n')
		{
			len++;
			i++;
		}
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char *s, t_map *map)
{
	unsigned long int	i;

	i = 0;
	while (i < map->width)
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	i++;
	while (i < ft_strlen(s) - map->width)
	{
		if (s[i] != '1' || s[i + map->width - 1] != '1')
			return (0);
		i += map->width + 1;
	}
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

t_game	*parse_map(char *berfile, t_game *game)
{
	int	fd;

	good_extension(game, berfile);
	fd = open(berfile, O_RDONLY);
	if (fd == -1)
		exit_game(game, "Invalid infile\n");
	game->map_info->s = get_map_str(fd);
	close(fd);
	if (!game->map_info->s)
		exit_game(game, "Invalid map\n");
	if (!get_dim(game->map_info->s, game->map_info))
		exit_game(game, "Invalid map dimensions\n");
	if (!check_if_rectangle(game->map_info->s, game->map_info))
		exit_game(game, "Invalid map is not a rectangle\n");
	if (!check_wall(game->map_info->s, game->map_info))
		exit_game(game, "Invalid map is not closed\n");
	if (!check_char(game->map_info->s))
		exit_game(game, "Invalid char in map\n");
	if (!check_playable(game->map_info->s))
		exit_game(game, "Map is not playable\n");
	if (!flood_fill(game->map_info->s))
	{
		exit_game(game, "Invalid map, some items are not reachable\n");
	}
	return (game);
}
