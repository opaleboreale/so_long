/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:25:16 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/12 11:17:56 by mferracc         ###   ########.fr       */
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
	if (game->monster)
		mlx_destroy_image(game->mlx_ptr, game->monster);
}

void	free_anim_utils(t_game *game)
{
	if (game->anim->bl0)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl0);
	if (game->anim->bl1)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl1);
	if (game->anim->bl2)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl2);
	if (game->anim->bl3)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl3);
	if (game->anim->bl4)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl4);
	if (game->anim->bl5)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl5);
	if (game->anim->bl6)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl6);
	if (game->anim->bl7)
		mlx_destroy_image(game->mlx_ptr, game->anim->bl7);
	if (game->anim->br0)
		mlx_destroy_image(game->mlx_ptr, game->anim->br0);
	if (game->anim->br1)
		mlx_destroy_image(game->mlx_ptr, game->anim->br1);
	if (game->anim->br2)
		mlx_destroy_image(game->mlx_ptr, game->anim->br2);
	if (game->anim->br3)
		mlx_destroy_image(game->mlx_ptr, game->anim->br3);
}

void	free_anim(t_game *game)
{
	free_anim_utils(game);
	if (game->anim->br4)
		mlx_destroy_image(game->mlx_ptr, game->anim->br4);
	if (game->anim->br5)
		mlx_destroy_image(game->mlx_ptr, game->anim->br5);
	if (game->anim->br6)
		mlx_destroy_image(game->mlx_ptr, game->anim->br6);
	if (game->anim->br7)
		mlx_destroy_image(game->mlx_ptr, game->anim->br7);
	if (game->anim->bst0)
		mlx_destroy_image(game->mlx_ptr, game->anim->bst0);
	if (game->anim->bst1)
		mlx_destroy_image(game->mlx_ptr, game->anim->bst1);
	if (game->anim->bst2)
		mlx_destroy_image(game->mlx_ptr, game->anim->bst2);
	if (game->anim->bst3)
		mlx_destroy_image(game->mlx_ptr, game->anim->bst3);
	if (game->anim->bst4)
		mlx_destroy_image(game->mlx_ptr, game->anim->bst4);
	if (game->anim->bst5)
		mlx_destroy_image(game->mlx_ptr, game->anim->bst5);
}

int	quit_game(t_game *game, char *s)
{
	free_img(game);
	if (game->anim)
	{
		free_anim(game);
		free(game->anim);
	}
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
