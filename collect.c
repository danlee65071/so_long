/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:22 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 22:01:25 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	no_collet_exit(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->count_collect == 0)
		close_game(game);
}

void	is_collect(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		game->count_collect--;
}
