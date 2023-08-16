/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:04:29 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/09 07:33:52 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->s = 0;
	map->height = 0;
	map->width = 0;
	return (map);
}

int	load_img_utils(t_game *game)
{
	int	x;

	x = SIZE;
	game->sky = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./textures/bg.xpm", &x, &x);
	if (!game->sky)
		return (0);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./textures/dungeon.xpm", &x, &x);
	if (!game->wall)
		return (0);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./textures/door_closed.xpm", &x, &x);
	if (!game->exit)
		return (0);
	return (1);
}

int	load_img(t_game *game)
{
	int	x;

	x = SIZE;
	if (!load_img_utils(game))
		return (0);
	game->sprite = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./textures/blob.xpm", &x, &x);
	if (!game->sprite)
		return (0);
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./textures/coin.xpm", &x, &x);
	if (!game->coin)
		return (0);
	game->open_door = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./textures/door_opened.xpm", &x, &x);
	if (!game->open_door)
		return (0);
	return (1);
}

t_game	*init_to_zero(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->mlx_ptr = 0;
	game->mlx_win = 0;
	game->map_info = 0;
	game->sky = 0;
	game->wall = 0;
	game->sprite = 0;
	game->exit = 0;
	game->coin = 0;
	game->open_door = 0;
	game->pos = 0;
	game->to_collect = 0;
	game->moves = 0;
	game->map = 0;
	return (game);
}

t_game	*init_game(char *berfile)
{
	t_game	*game;

	game = init_to_zero();
	if (!game)
		return (0);
	game->map_info = init_map();
	if (!game->map_info)
	{
		free(game);
		return (0);
	}
	game = parse_map(berfile, game);
	if (!get_pos(game))
		quit_game(game, "get_pos error\n");
	game->map = ft_split(game->map_info->s, '\n');
	if (!game->map)
		quit_game(game, "Error on split s to map\n");
	return (game);
}
