/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:10:17 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/09 07:44:25 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_putendl_fd("Error: invalid number of arguments", 2), 1);
	game = init_game(av[1]);
	if (!game)
		return (0);
	if (!start_play(game))
		quit_game(game, "error on start_play\n");
	quit_game(game, 0);
	return (0);
}
