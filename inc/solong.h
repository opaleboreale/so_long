/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:29:17 by mferracc          #+#    #+#             */
/*   Updated: 2023/03/12 11:13:53 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../mlx_linux/mlx.h"

typedef struct s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}	t_coord;

typedef struct s_position
{
	t_coord	*p;
	t_coord	*c;
	t_coord	*e;
}	t_position;

typedef struct s_map
{
	char				*s;
	unsigned long int	height;
	unsigned long int	width;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map		*map_info;
	void		*sky;
	void		*wall;
	void		*sprite;
	void		*exit;
	void		*coin;
	void		*open_door;
	t_position	*pos;
	int			to_collect;
	int			moves;
	char		**map;
}	t_game;

# define SIZE 30

/****       Utils       ****/
void	error(char *s);
void	exit_game(t_game *game, char *s);

/****       Init       ****/
t_game	*init_game(char *berfile);
int		load_img(t_game *game);

/****       Clear all       ****/
void	ft_clear_game(t_game *game);
void	clear_pos(t_position *pos);
void	free_double_str(char **s);

/****       Parsing       ****/
t_game	*parse_map(char *berfile, t_game *game);
int		check_char(char *s);
int		check_playable(char *s);
void	check_screen(t_game *game);

/****       Get map       ****/
char	*get_map_str(int fd);

/****       Explore       ****/
int		flood_fill(char *s);

/****       Start play       ****/
int		display_score(t_game *game);
int		start_play(t_game *game);
int		display_map(t_game *game);

/****       Quit play       ****/
int		quit_game(t_game *game, char *s);
int		close_cross(t_game *game);

/****       Game loop       ****/
void	game_loop(t_game *game);
void	move(t_game *game, char *move);

/****       Get pos       ****/
t_game	*get_pos(t_game *game);
t_coord	*init_c_pos(t_game *game);
int		count_col(char *s);
t_coord	*search_pos(t_coord *xy, char **M, char type);

/****       Move       ****/
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);

#endif
