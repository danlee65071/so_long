/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:27:23 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 21:58:31 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char			*buf;
	int				byte_was_read;
	char			*point;
	char			*tmp;
	char			*line;
}	t_gnl;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *str);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

#endif