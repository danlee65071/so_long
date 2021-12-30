/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:44 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/11 16:05:02 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_row(t_game *game, char **argv)
{
	int		fd;
	char	*line;

	game->row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Bad file descriptor!\n");
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->row++;
	}
}
