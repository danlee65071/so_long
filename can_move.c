/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:21:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 22:01:06 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	condition_for_move(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1' ||
			(game->map[i][j] == 'E' && game->count_collect > 0))
		return (FALSE);
	return (TRUE);
}

static int	_can_move(int button, int res, t_game *game)
{
	if (button == W)
	{
		res = condition_for_move(game, --game->pl_i, game->pl_j);
		game->pl_i++;
	}
	else if (button == S)
	{
		res = condition_for_move(game, ++game->pl_i, game->pl_j);
		game->pl_i--;
	}
	else if (button == D)
	{
		res = condition_for_move(game, game->pl_i, ++game->pl_j);
		game->pl_j--;
	}
	else if (button == A)
	{
		res = condition_for_move(game, game->pl_i, --game->pl_j);
		game->pl_j++;
	}
	return (res);
}

int	can_move(int button, t_game *game)
{
	int	res;

	res = 2;
	res = _can_move(button, res, game);
	if (res == FALSE)
		return (FALSE);
	return (TRUE);
}
