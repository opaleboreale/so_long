/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:57:11 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 13:00:24 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	search_exit(t_game *game, int i, int j, char dir)
{
	char	**map;

	map = game->map;
	if (dir == 'L' && map[i][j - 1] == 'E')
		quit_game(game, 0);
	else if (dir == 'R' && map[i][j + 1] == 'E')
		quit_game(game, 0);
	else if (dir == 'U' && map[i - 1][j] == 'E')
		quit_game(game, 0);
	else if (dir == 'D' && map[i + 1][j] == 'E')
		quit_game(game, 0);
}

int	is_collected(t_game *game, int i, int j, char dir)
{
	char	**map;

	map = game->map;
	if (dir == 'L' && map[i][j - 1] == 'C')
		return (1);
	else if (dir == 'R' && (map[i][j + 1] == '0' || map[i][j + 1] == 'C'))
		return (1);
	else if (dir == 'U' && (map[i - 1][j] == '0' || map[i - 1][j] == 'C'))
		return (1);
	else if (dir == 'D' && (map[i + 1][j] == '0' || map[i + 1][j] == 'C'))
		return (1);
	return (0);
}

int	check_move(t_game *game, int i, int j, char dir)
{
	char	**map;

	map = game->map;
	if (game->to_collect == 0)
		search_exit(game, i, j, dir);
	if (dir == 'L' && map[i][j - 1] == '0')
		return (1);
	else if (dir == 'R' && map[i][j + 1] == '0')
		return (1);
	else if (dir == 'U' && map[i - 1][j] == '0')
		return (1);
	else if (dir == 'D' && map[i + 1][j] == '0')
		return (1);
	else if (is_collected(game, i, j, dir))
	{
		game->to_collect--;
		return (1);
	}
	return (0);
}

void	move(t_game *game, char *move)
{
	int	x;
	int	y;

	x = game->pos->p->x;
	y = game->pos->p->y;
	if (ft_strncmp(move, "up", 3) == 0 && check_move(game, y, x, 'U'))
		move_up(game, x, y);
	else if (ft_strncmp(move, "down", 5) == 0 && check_move(game, y, x, 'D'))
		move_down(game, x, y);
	else if (ft_strncmp(move, "left", 5) == 0 && check_move(game, y, x, 'L'))
		move_left(game, x, y);
	else if (ft_strncmp(move, "right", 6) == 0 && check_move(game, y, x, 'R'))
		move_right(game, x, y);
}
