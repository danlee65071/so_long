/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_flags_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:59 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 20:39:13 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_flags_player(t_game *game)
{
	game->flag_right = 0;
	game->flag_left = 0;
	game->flag_front = 0;
	game->flag_back = 0;
}
