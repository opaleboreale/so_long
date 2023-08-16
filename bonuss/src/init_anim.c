/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:03:43 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/09 08:06:21 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	init_anim_l(t_anim *anim, t_game *game)
{
	int		x;
	int		y;
	char	**file;

	file = ft_split("./textures/bl_left/bl0.xpm	\
	./textures/bl_left/bl1.xpm	\
	./textures/bl_left/bl2.xpm	\
	./textures/bl_left/bl3.xpm	\
	./textures/bl_left/bl4.xpm	\
	./textures/bl_left/bl5.xpm	\
	./textures/bl_left/bl6.xpm	\
	./textures/bl_left/bl7.xpm", '\t');
	if (!file)
		return (0);
	x = W;
	y = SIZE;
	anim->bl0 = mlx_xpm_file_to_image(game->mlx_ptr, file[0], &x, &y);
	anim->bl1 = mlx_xpm_file_to_image(game->mlx_ptr, file[1], &x, &y);
	anim->bl2 = mlx_xpm_file_to_image(game->mlx_ptr, file[2], &x, &y);
	anim->bl3 = mlx_xpm_file_to_image(game->mlx_ptr, file[3], &x, &y);
	anim->bl4 = mlx_xpm_file_to_image(game->mlx_ptr, file[4], &x, &y);
	anim->bl5 = mlx_xpm_file_to_image(game->mlx_ptr, file[5], &x, &y);
	anim->bl6 = mlx_xpm_file_to_image(game->mlx_ptr, file[6], &x, &y);
	anim->bl7 = mlx_xpm_file_to_image(game->mlx_ptr, file[7], &x, &y);
	free_double_str(file);
	if (!anim->bl0 || !anim->bl1 || !anim->bl2 || !anim->bl3 || \
			!anim->bl4 || !anim->bl5 || !anim->bl6 || !anim->bl7)
		return (0);
	return (1);
}

int	init_anim_r(t_anim *anim, t_game *game)
{
	int		x;
	int		y;
	char	**file;

	file = ft_split("./textures/bl_right/br0.xpm	\
	./textures/bl_right/br1.xpm	\
	./textures/bl_right/br2.xpm	\
	./textures/bl_right/br3.xpm	\
	./textures/bl_right/br4.xpm	\
	./textures/bl_right/br5.xpm	\
	./textures/bl_right/br6.xpm	\
	./textures/bl_right/br7.xpm", '\t');
	if (!file)
		return (0);
	x = W;
	y = SIZE;
	anim->br0 = mlx_xpm_file_to_image(game->mlx_ptr, file[0], &x, &y);
	anim->br1 = mlx_xpm_file_to_image(game->mlx_ptr, file[1], &x, &y);
	anim->br2 = mlx_xpm_file_to_image(game->mlx_ptr, file[2], &x, &y);
	anim->br3 = mlx_xpm_file_to_image(game->mlx_ptr, file[3], &x, &y);
	anim->br4 = mlx_xpm_file_to_image(game->mlx_ptr, file[4], &x, &y);
	anim->br5 = mlx_xpm_file_to_image(game->mlx_ptr, file[5], &x, &y);
	anim->br6 = mlx_xpm_file_to_image(game->mlx_ptr, file[6], &x, &y);
	anim->br7 = mlx_xpm_file_to_image(game->mlx_ptr, file[7], &x, &y);
	free_double_str(file);
	if (!anim->br0 || !anim->br1 || !anim->br2 || !anim->br3 || \
			!anim->br4 || !anim->br5 || !anim->br6 || !anim->br7)
		return (0);
	return (1);
}

int	init_anim_st(t_anim *anim, t_game *game)
{
	int		x;
	int		y;
	char	**file;

	file = ft_split("./textures/bl_st/bl_st0.xpm	\
	./textures/bl_st/bl_st1.xpm	\
	./textures/bl_st/bl_st2.xpm	\
	./textures/bl_st/bl_st3.xpm	\
	./textures/bl_st/bl_st4.xpm	\
	./textures/bl_st/bl_st5.xpm", '\t');
	if (!file)
		return (0);
	x = SIZE;
	y = H;
	anim->bst0 = mlx_xpm_file_to_image(game->mlx_ptr, file[0], &x, &y);
	anim->bst1 = mlx_xpm_file_to_image(game->mlx_ptr, file[1], &x, &y);
	anim->bst2 = mlx_xpm_file_to_image(game->mlx_ptr, file[2], &x, &y);
	anim->bst3 = mlx_xpm_file_to_image(game->mlx_ptr, file[3], &x, &y);
	anim->bst4 = mlx_xpm_file_to_image(game->mlx_ptr, file[4], &x, &y);
	anim->bst5 = mlx_xpm_file_to_image(game->mlx_ptr, file[5], &x, &y);
	free_double_str(file);
	if (!anim->bst0 || !anim->bst1 || !anim->bst2 || !anim->bst3 || \
			!anim->bst4 || !anim->bst5)
		return (0);
	return (1);
}

int	load_anim(t_game *game)
{
	game->anim = init_anim();
	if (!game->anim)
		return (0);
	if (!init_anim_l(game->anim, game))
		return (0);
	if (!init_anim_r(game->anim, game))
		return (0);
	if (!init_anim_st(game->anim, game))
		return (0);
	return (1);
}
