/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:19:29 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/26 15:50:27 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <limits.h>

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printdeci(int n, int *len);
int	ft_printud(unsigned int n, int *len);
int	ft_printnbr_hex(unsigned int n, char *base, int *len);
int	ft_printpointer_hex(unsigned long address, char *base, int *len);
int	ft_printpointer(void *p);

#endif
