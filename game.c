/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:10 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/11 16:09:32 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	if (argc < 2)
		error("Map not found\n");
	count_row(&game, argv);
	init_struct(&game);
	check_map(&game, argv);
	count_collect(&game);
	create_game(&game);
	init_img(&game);
	position_player(&game);
	mlx_hook(game.win, PRESS, 0, &move, &game);
	mlx_hook(game.win, EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &draw, &game);
	mlx_loop(game.mlx);
}
