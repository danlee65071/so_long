/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:28 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 22:01:33 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'C')
				game->count_collect++;
			j++;
		}
		i++;
	}
	if (game->count_collect == 0)
		error("Collectibles not found\n");
}
