/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:29 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/08 12:56:33 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	last_check(char **M)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (M[i])
	{
		j = 0;
		while (M[i][j])
		{
			if (M[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	can_move(char **M, int i, int j)
{
	int	move;

	move = 0;
	if (M[i][j - 1] == '0' || M[i][j - 1] == 'C')
	{
		M[i][j - 1] = 'P';
		move++;
	}
	if (M[i][j + 1] == '0' || M[i][j + 1] == 'C')
	{
		M[i][j + 1] = 'P';
		move++;
	}
	if (M[i - 1][j] == '0' || M[i - 1][j] == 'C')
	{
		M[i - 1][j] = 'P';
		move++;
	}
	if (M[i + 1][j] == '0' || M[i + 1][j] == 'C')
	{
		M[i + 1][j] = 'P';
		move++;
	}
	return (move);
}

void	explore_map(char **M)
{
	int	i;
	int	j;

	i = 0;
	while (M[i])
	{
		j = 0;
		while (M[i][j])
		{
			if (M[i][j] == 'P')
			{
				if (can_move(M, i, j))
				{
					i = -1;
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

int	flood_fill(char *s)
{
	char	**map;
	int		ret;

	ret = 0;
	map = ft_split(s, '\n');
	if (!map)
		return (0);
	explore_map(map);
	if (last_check(map))
		ret = 1;
	free_double_str(map);
	return (ret);
}
