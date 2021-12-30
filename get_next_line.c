/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:20 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 20:37:08 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	point_not_null(char *point, char **line, char **ost)
{
	char	*tmp;

	*point = '\0';
	tmp = *line;
	*line = ft_strdup(*ost);
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(*line, "\n");
	free(tmp);
	point++;
	ft_strlcpy(*ost, point, ft_strlen(point) + 1);
}

static char	*check_ost(char **ost, char **line)
{
	char	*point;
	char	*tmp;

	point = NULL;
	*line = ft_strdup("");
	if (*ost)
	{
		point = ft_strchr(*ost, '\n');
		if (point != NULL)
			point_not_null(point, line, ost);
		else
		{
			tmp = *line;
			*line = ft_strdup(*ost);
			free(tmp);
			free(*ost);
			*ost = NULL;
		}
	}
	return (point);
}

static int	loop(int fd, t_gnl *gnl, char **ost)
{
	gnl->buf[gnl->byte_was_read] = '\0';
	gnl->point = ft_strchr(gnl->buf, '\n');
	if (gnl->point != NULL)
	{
		*gnl->point = '\0';
		gnl->point++;
		*ost = ft_strdup(gnl->point);
		gnl->tmp = gnl->line;
		gnl->line = ft_strjoin(gnl->tmp, gnl->buf);
		free(gnl->tmp);
		gnl->tmp = gnl->line;
		gnl->line = ft_strjoin(gnl->line, "\n");
		free(gnl->tmp);
		free(gnl->buf);
		return (1);
	}
	gnl->tmp = gnl->line;
	gnl->line = ft_strjoin(gnl->tmp, gnl->buf);
	free(gnl->tmp);
	gnl->byte_was_read = read(fd, gnl->buf, BUFFER_SIZE);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*ost;
	t_gnl			gnl;

	if (fd < 0 || fd > 19 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.point = check_ost(&ost, &gnl.line);
	if (gnl.point != NULL)
		return (gnl.line);
	gnl.buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	gnl.byte_was_read = read(fd, gnl.buf, BUFFER_SIZE);
	while (!gnl.point && (gnl.byte_was_read != 0))
		if (loop(fd, &gnl, &ost) == 1)
			return (gnl.line);
	free(gnl.buf);
	if (*gnl.line != '\0')
		return (gnl.line);
	else
		free(gnl.line);
	return (NULL);
}
