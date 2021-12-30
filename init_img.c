/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:27 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 20:36:42 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void	init_img(t_game *game)
{
	int	img_w;
	int	img_h;

	img_w = 10;
	img_h = 10;
	game->food = mlx_xpm_file_to_image(game->mlx,
			"assets/food.xpm", &img_w, &img_h);
	game->player_front = mlx_xpm_file_to_image(game->mlx,
			"assets/player_front.xpm", &img_w, &img_h);
	game->player_back = mlx_xpm_file_to_image(game->mlx,
			"assets/player_back.xpm", &img_w, &img_h);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right.xpm", &img_w, &img_h);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left.xpm", &img_w, &img_h);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &img_w, &img_h);
	game->empty = mlx_xpm_file_to_image(game->mlx,
			"assets/empty.xpm", &img_w, &img_h);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &img_w, &img_h);
}
