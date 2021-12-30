/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:46 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 22:02:22 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_a(t_game *game);

int	move(int button, t_game *game)
{
	int	res;

	res = can_move(button, game);
	if (button == 53)
		close_game(game);
	if (res == TRUE)
	{
		if (button == W)
			move_w(game);
		else if (button == S)
			move_s(game);
		else if (button == D)
			move_d(game);
		else if (button == A)
			move_a(game);
	}
	return (0);
}

void	move_w(t_game *game)
{
	is_collect(game, --game->pl_i, game->pl_j);
	game->pl_i++;
	no_collet_exit(game, --game->pl_i, game->pl_j);
	game->pl_i++;
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[--game->pl_i][game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_back = 1;
	game->steps++;
	printf("Step : %d\n", game->steps);
}

void	move_s(t_game *game)
{
	is_collect(game, ++game->pl_i, game->pl_j);
	game->pl_i--;
	no_collet_exit(game, ++game->pl_i, game->pl_j);
	game->pl_i--;
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[++game->pl_i][game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_front = 1;
	game->steps++;
	printf("Step : %d\n", game->steps);
}

void	move_d(t_game *game)
{
	is_collect(game, game->pl_i, ++game->pl_j);
	game->pl_j--;
	no_collet_exit(game, game->pl_i, ++game->pl_j);
	game->pl_j--;
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[game->pl_i][++game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_right = 1;
	game->steps++;
	printf("Step : %d\n", game->steps);
}

void	move_a(t_game *game)
{
	is_collect(game, game->pl_i, --game->pl_j);
	game->pl_j++;
	no_collet_exit(game, game->pl_i, --game->pl_j);
	game->pl_j++;
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[game->pl_i][--game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_left = 1;
	game->steps++;
	printf("Step : %d\n", game->steps);
}
