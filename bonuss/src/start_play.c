/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:26:20 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/12 11:11:41 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		quit_game(game, 0);
	}
	if (game->busy == 1)
		return (0);
	else if (keycode == 65362)
		move(game, "up");
	else if (keycode == 65364)
		move(game, "down");
	else if (keycode == 65361)
		move(game, "left");
	else if (keycode == 65363)
	{
		move(game, "right");
	}
	return (0);
}

int	display_score(t_game *game)
{
	char	*score;

	score = ft_itoa(game->moves);
	if (!score)
		return (0);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 40, 50, 0xFF0000, score);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 41, 50, 0xFF0000, score);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 40, 51, 0xFF0000, score);
	free(score);
	return (0);
}

void	display_tiles(t_game *game, char **map, int i, int j)
{
	if (map[i][j] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, \
				SIZE * j, SIZE * i);
	else if (map[i][j] == 'E' && game->to_collect)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, \
				SIZE * j, SIZE * i);
	else if (map[i][j] == 'E' && !game->to_collect)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->open_door, \
				SIZE * j, SIZE * i);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->sprite, \
				SIZE * j, SIZE * i);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->coin, \
				SIZE * j, SIZE * i);
	else if (map[i][j] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->sky, \
				SIZE * j, SIZE * i);
	else if (map[i][j] == 'M')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->monster, \
				SIZE * j, SIZE * i);
}

int	display_map(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			display_tiles(game, map, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

int	start_play(t_game *game)
{	
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		return (0);
	}
	check_screen(game);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_info->width * \
			SIZE, game->map_info->height * SIZE, "Blobby's World");
	if (!game->mlx_win)
		return (0);
	if (!load_img(game))
		quit_game(game, "cannot load the xpm\n");
	if (!display_map(game))
	{
		return (0);
	}
	mlx_loop_hook (game->mlx_ptr, display_map, game);
	mlx_loop_hook(game->mlx_ptr, display_score, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0, close_cross, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
