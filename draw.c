/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:04 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 20:50:49 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			mlx_put_image_to_window(game->mlx,
				game->win, game->empty, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, int i, int j)
{
	if (game->flag_right == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_right, j * 64, i * 64);
	else if (game->flag_left == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_left, j * 64, i * 64);
	else if (game->flag_back == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_back, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_front, j * 64, i * 64);
}

void	draw_other(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, j * 64, i * 64);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->food, j * 64, i * 64);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->exit, j * 64, i * 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->empty, j * 64, i * 64);
}

int	draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P')
				draw_player(game, i, j);
			else
				draw_other(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
