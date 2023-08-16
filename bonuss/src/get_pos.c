/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:01:43 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 13:02:50 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

t_coord	*search_pos(t_coord *xy, char **map, char type)
{
	int	i;
	int	j;

	xy->next = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == type)
			{
				map[i][j] = '0';
				xy->x = j;
				xy->y = i;
				return (xy);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_coord	*init_p_pos(t_game *game)
{
	char	**map;

	map = ft_split(game->map_info->s, '\n');
	if (!map)
		return (0);
	game->pos->p = malloc(sizeof(t_coord));
	if (!game->pos->p)
		return (0);
	if (!search_pos(game->pos->p, map, 'P'))
		return (0);
	free_double_str(map);
	return (game->pos->p);
}

int	count_col(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

t_coord	*init_e_pos(t_game *game)
{
	char	**map;

	map = ft_split(game->map_info->s, '\n');
	if (!map)
		return (0);
	game->pos->e = malloc(sizeof(t_coord));
	if (!game->pos->e)
		return (0);
	if (!search_pos(game->pos->e, map, 'E'))
		return (0);
	free_double_str(map);
	return (game->pos->e);
}

t_game	*get_pos(t_game *game)
{
	game->pos = malloc(sizeof(t_position));
	if (!game->pos)
		return (0);
	game->pos->p = 0;
	game->pos->c = 0;
	game->pos->e = 0;
	game->pos->p = init_p_pos(game);
	if (!game->pos->p)
		quit_game(game, "Error on init_p_pos\n");
	game->pos->c = init_c_pos(game);
	if (!game->pos->c)
		quit_game(game, "Error on init_c_pos\n");
	game->pos->e = init_e_pos(game);
	if (!game->pos->e)
		quit_game(game, "Error on init_e_pos\n");
	return (game);
}
