/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:03:16 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 13:04:02 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	init_init(t_game *game, char **map)
{
	game->to_collect = count_col(game->map_info->s);
	game->pos->c = malloc(sizeof(t_coord));
	if (!game->pos->c)
		return (0);
	if (!search_pos(game->pos->c, map, 'C'))
	{
		free(game->pos->c);
		return (0);
	}
	return (1);
}

t_coord	*init_c_pos(t_game *game)
{
	char	**map;
	t_coord	*tmp;
	int		i;

	map = ft_split(game->map_info->s, '\n');
	if (!map)
		return (0);
	init_init(game, map);
	tmp = game->pos->c;
	i = 0;
	while (i < game->to_collect - 1)
	{
		tmp->next = malloc(sizeof(t_coord));
		if (!tmp->next)
			return (tmp);
		tmp->next = search_pos(tmp->next, map, 'C');
		tmp = tmp->next;
		i++;
	}
	free_double_str(map);
	return (game->pos->c);
}
