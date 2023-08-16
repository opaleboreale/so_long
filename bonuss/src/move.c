/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:23:30 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 14:55:14 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	move_up(t_game *game, int x, int y)
{
	game->map[y - 1][x] = 'P';
	play_anim_up(game, x, y);
	while (game->busy == 2)
	{
		sleep(game->busy);
	}
	game->map[y][x] = '0';
	game->pos->p->y -= 1;
	game->moves++;
	display_map(game);
	display_score(game);
	ft_printf("%d\n", game->moves);
}

void	move_down(t_game *game, int x, int y)
{
	game->map[y + 1][x] = 'P';
	game->map[y][x] = '0';
	game->pos->p->y += 1;
	game->moves++;
	display_map(game);
	display_score(game);
	ft_printf("%d\n", game->moves);
}

void	move_left(t_game *game, int x, int y)
{
	game->map[y][x - 1] = 'P';
	play_anim_right(game, x, y);
	while (game->busy == 2)
	{
		sleep(game->busy);
	}
	game->map[y][x] = '0';
	game->pos->p->x -= 1;
	game->moves++;
	display_map(game);
	display_score(game);
	ft_printf("%d\n", game->moves);
}

void	move_right(t_game *game, int x, int y)
{
	game->map[y][x + 1] = 'P';
	play_anim_left(game, x, y);
	while (game->busy == 2)
	{
		sleep(game->busy);
	}
	game->map[y][x] = '0';
	game->pos->p->x += 1;
	game->moves++;
	display_map(game);
	display_score(game);
	ft_printf("%d\n", game->moves);
}
