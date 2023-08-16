/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:13:24 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/12 11:19:15 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	check_screen(t_game *game)
{
	int	x;
	int	y;

	mlx_get_screen_size(game->mlx_ptr, &x, &y);
	if (x < SIZE * (int)game->map_info->width || y < SIZE * \
			(int)game->map_info->height)
		quit_game(game, "Error: map too large compared to screen size\n");
}

int	check_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'C' && \
		s[i] != 'E' && s[i] != 'P' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_item(char *s)
{
	int	i;
	int	collectible;
	int	player;
	int	exit;

	i = 0;
	collectible = 0;
	player = 0;
	exit = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			collectible++;
		else if (s[i] == 'E')
			exit++;
		else if (s[i] == 'P')
			player++;
		i++;
	}
	if (collectible == 0 || exit > 1 || player > 1)
		return (0);
	return (1);
}

int	check_playable(char *s)
{
	if (!check_item(s))
		return (0);
	return (1);
}
