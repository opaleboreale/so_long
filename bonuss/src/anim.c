/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:47:01 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 13:57:29 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	display_img(t_game *game, void *img, int x, int y)
{
	int	m;

	m = 0;
	while (m < 8000)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, x, y);
		m++;
	}
}

int	play_anim_right(t_game *game, int x, int y)
{
	int	m;

	m = 0;
	game->busy = 2;
	display_img(game, game->anim->bl0, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl1, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl2, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl3, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl4, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl5, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl6, SIZE * x - 30, SIZE * y);
	display_img(game, game->anim->bl7, SIZE * x - 30, SIZE * y);
	game->busy = 1;
	return (1);
}

int	play_anim_left(t_game *game, int x, int y)
{
	int	m;

	m = 0;
	game->busy = 2;
	display_img(game, game->anim->br0, SIZE * x, SIZE * y);
	display_img(game, game->anim->br1, SIZE * x, SIZE * y);
	display_img(game, game->anim->br2, SIZE * x, SIZE * y);
	display_img(game, game->anim->br3, SIZE * x, SIZE * y);
	display_img(game, game->anim->br4, SIZE * x, SIZE * y);
	display_img(game, game->anim->br5, SIZE * x, SIZE * y);
	display_img(game, game->anim->br6, SIZE * x, SIZE * y);
	display_img(game, game->anim->br7, SIZE * x, SIZE * y);
	game->busy = 1;
	return (1);
}

int	play_anim_up(t_game *game, int x, int y)
{
	int	m;

	m = 0;
	game->busy = 2;
	display_img(game, game->anim->bst0, SIZE * x, SIZE * y - 30);
	display_img(game, game->anim->bst1, SIZE * x, SIZE * y - 30);
	display_img(game, game->anim->bst2, SIZE * x, SIZE * y - 30);
	display_img(game, game->anim->bst3, SIZE * x, SIZE * y - 30);
	display_img(game, game->anim->bst4, SIZE * x, SIZE * y - 30);
	display_img(game, game->anim->bst5, SIZE * x, SIZE * y - 30);
	game->busy = 1;
	return (1);
}
