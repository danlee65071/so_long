/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:28:25 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/11 16:04:11 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
// # include "mlx/mlx_int.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

# define TRUE	1
# define FALSE	0

// button
# define W		13
# define S		1
# define A		0
# define D		2
# define ESC	53
# define PRESS	2
# define EXIT	17

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		h;
	int		w;
}			t_img;

typedef struct s_game
{
	void	*mlx_win;
	void	*mlx;
	void	*win;
	int		coord_x;
	int		coord_y;
	void	*img;
	char	**map;
	void	*food;
	void	*wall;
	void	*exit;
	void	*empty;
	void	*player_front;
	void	*player_back;
	void	*player_right;
	void	*player_left;
	int		flag_front;
	int		flag_back;
	int		flag_right;
	int		flag_left;
	int		row;
	int		column;
	int		pl_i;
	int		pl_j;
	int		steps;
	int		count_collect;
}	t_game;

typedef struct s_check
{
	char		*line;
	int			count_line;
	int			fd;
	size_t		len_prev_line;
	int			i;
	int			len_first;
}	t_check;

int		init_struct(t_game *game);
char	*get_next_line(int fd);
void	check_map(t_game *game, char **argv);
void	create_game(t_game *game);
int		draw(t_game *game);
void	init_img(t_game *game);
void	count_row(t_game *game, char **argv);
void	position_player(t_game *game);
int		move(int button, t_game *game);
int		can_move(int button, t_game *game);
int		close_game(t_game *game);
void	delete_flags_player(t_game *game);
void	count_collect(t_game *game);
void	no_collet_exit(t_game *game, int i, int j);
void	is_collect(t_game *game, int i, int j);
void	ft_putstr_fd(char *s, int fd);
void	error(char *mes);
void	_check_map(t_game *game);
void	check_first_and_last_line(char *line);
void	check_rectangular(size_t len_first,
			char *line, int num_row, t_game *game);

#endif
