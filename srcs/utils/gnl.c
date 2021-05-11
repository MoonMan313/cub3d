/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:08:08 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:18:14 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int	get_buf(char **buf, char **line)
{
	char		*tmp;
	int			n;

	n = ft_strn(*buf);
	if (n != -1)
	{
		if (n != 0)
			*line = line_join(*line, *buf, n);
		tmp = ft_strdup(&(*buf)[n + 1]);
		free(*buf);
		*buf = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	*line = line_join(*line, *buf, ft_strlen(*buf));
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		l;

	buf = ft_strdup("");
	if (!line || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	buf = (char *)malloc(sizeof(char));
	if (!buf)
		return (-1);
	l = read(fd, buf, 1);
	while (l > 0)
	{
		buf[l] = '\0';
		if (get_buf(&buf, line))
			break ;
		l = read(fd, buf, 1);
	}
	if (l == 0)
	{
		free(buf);
		buf = NULL;
	}
	return (l);
}
