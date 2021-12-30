/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:22:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/11 16:03:46 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	len_first_line(char *line, t_game *game)
{
	int	len_first_line;

	len_first_line = ft_strlen(line);
	game->column = len_first_line - 1;
	return (len_first_line);
}

void	init_struct_map(t_check *check, t_game *game, char **argv)
{
	check->count_line = 0;
	check->len_prev_line = 0;
	check->fd = open(argv[1], O_RDONLY);
	if (check->fd == -1)
		error("Bad file descriptor!\n");
	check->line = get_next_line(check->fd);
	if (check->line == NULL)
		error("Empty map\n");
	check->len_first = len_first_line(check->line, game);
	check->count_line++;
	game->map[0] = ft_strdup(check->line);
	free(check->line);
}

static void	check_wrong_ch(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
			error("Wrong symbols\n");
		i++;
	}
}

static void	check_first_and_last_ch(char *line)
{
	int		i;
	size_t	len_line;

	i = 0;
	len_line = ft_strlen(line);
	if (line[i] != '1' || line[len_line - 2] != '1')
		error("Map without wall\n");
}

void	check_map(t_game *game, char **argv)
{
	t_check	check;
	int		i;

	i = 1;
	init_struct_map(&check, game, argv);
	while (check.line)
	{
		check_rectangular(check.len_first, check.line, check.count_line, game);
		check_first_and_last_ch(check.line);
		if (check.count_line == 1 || check.count_line == game->row)
			check_first_and_last_line(check.line);
		check_wrong_ch(check.line);
		check.line = get_next_line(check.fd);
		if (check.line != NULL)
		{
			game->map[i] = ft_strdup(check.line);
			free(check.line);
		}
		i++;
		check.count_line++;
	}
	game->map[i] = NULL;
	_check_map(game);
}
