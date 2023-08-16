/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:21:55 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/09 08:03:53 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	init_sides(t_anim *anim)
{
	anim->bl0 = 0;
	anim->bl1 = 0;
	anim->bl2 = 0;
	anim->bl3 = 0;
	anim->bl4 = 0;
	anim->bl5 = 0;
	anim->bl6 = 0;
	anim->bl7 = 0;
	anim->br0 = 0;
	anim->br1 = 0;
	anim->br2 = 0;
	anim->br3 = 0;
	anim->br4 = 0;
	anim->br5 = 0;
	anim->br6 = 0;
	anim->br7 = 0;
}

t_anim	*init_anim(void)
{
	t_anim	*anim;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (0);
	anim->bst0 = 0;
	anim->bst1 = 0;
	anim->bst2 = 0;
	anim->bst3 = 0;
	anim->bst4 = 0;
	anim->bst5 = 0;
	init_sides(anim);
	return (anim);
}
