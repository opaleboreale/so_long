/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:21:07 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/12 11:19:01 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	close_cross(t_game *game)
{
	quit_game(game, 0);
	return (0);
}

void	free_img(t_game *game)
{
	if (game->sky)
		mlx_destroy_image(game->mlx_ptr, game->sky);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->sprite)
		mlx_destroy_image(game->mlx_ptr, game->sprite);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->coin)
		mlx_destroy_image(game->mlx_ptr, game->coin);
	if (game->open_door)
		mlx_destroy_image(game->mlx_ptr, game->open_door);
}

int	quit_game(t_game *game, char *s)
{
	free_img(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->pos)
		clear_pos(game->pos);
	if (game->map)
		free_double_str(game->map);
	ft_clear_game(game);
	if (s)
		error(s);
	else
		exit(0);
	return (0);
}
