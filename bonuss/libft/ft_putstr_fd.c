/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:58:23 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/09 05:01:08 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char	*s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	ft_putstr_fd("HELLO", 1);
	return (0);
}
*/
