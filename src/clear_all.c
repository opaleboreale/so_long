/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:49:02 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 12:51:25 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	ft_clear_map(t_map *map)
{
	if (map->s)
	{
		free(map->s);
		map->s = 0;
	}
	free(map);
	map = 0;
}

void	ft_clear_game(t_game *game)
{
	if (game->map_info)
		ft_clear_map(game->map_info);
	free(game);
	game = 0;
}

void	clear_pos_c(t_coord *xy)
{
	t_coord	*tmp;

	tmp = xy;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(xy);
		xy = tmp;
	}
	free(tmp);
}

void	clear_pos(t_position *pos)
{
	if (pos->p)
		free(pos->p);
	if (pos->c)
		clear_pos_c(pos->c);
	if (pos->e)
		free(pos->e);
	free(pos);
}
