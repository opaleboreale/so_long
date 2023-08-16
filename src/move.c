/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:11:46 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 13:38:40 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	move_up(t_game *game, int x, int y)
{
	game->map[y - 1][x] = 'P';
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
	game->map[y][x] = '0';
	game->pos->p->x += 1;
	game->moves++;
	display_map(game);
	display_score(game);
	ft_printf("%d\n", game->moves);
}
