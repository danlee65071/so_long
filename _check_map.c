/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:22:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 21:57:16 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_and_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			error("Map without wall\n");
		i++;
	}
}

void	check_rectangular(size_t len_first,
	char *line, int num_row, t_game *game)
{
	size_t	len_line;

	if (num_row == game->row)
		len_line = ft_strlen(line) + 1;
	else
		len_line = ft_strlen(line);
	if (len_first != len_line)
		error("Is not rectangle\n");
}

static void	check_one_player(t_game *game)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P')
				count_player++;
			if (count_player > 1)
				error("More than one player\n");
			j++;
		}
		i++;
	}
	if (count_player != 1)
		error("Player not found\n");
}

static void	check_one_exit(t_game *game)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'E')
				count_exit++;
			if (count_exit > 1)
				error("More than one exit\n");
			j++;
		}
		i++;
	}
	if (count_exit != 1)
		error("Exit not found\n");
}

void	_check_map(t_game *game)
{
	check_one_player(game);
	check_one_exit(game);
}
