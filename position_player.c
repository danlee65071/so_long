/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:25:17 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 20:36:51 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P')
			{
				game->pl_i = i;
				game->pl_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
