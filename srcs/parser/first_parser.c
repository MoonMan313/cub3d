/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:12:33 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:18:44 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

static int	is_char_map(char c)
{
	if (c && (c == ' ' || c == '1' || c == '0' || c == '2' || c == 'N' \
		|| c == 'S' || c == 'E' || c == 'W'))
		return (1);
	return (0);
}

int	check_len_map_line(char *line, t_cub *cub)
{
	int			i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '1')
	{
		i++;
		while (is_char_map(line[i]))
			i++;
		if (line[i] == '\0')
		{
			if (i > cub->map_width)
				cub->map_width = i;
			return (i);
		}
	}
	error_param(8);
	return (0);
}

int	first_check_map(char *line)
{
	static char	buf[] = "R  NO SO WE EA S  F  C  ";
	int			i;

	i = 0;
	if (*line == '\0')
		return (0);
	if (line[0] == ' ')
		error_param(7);
	while (buf[i])
	{
		if ((line[0] == buf[i]) && (line[1] == buf[i + 1]))
		{
			buf[i] = ' ';
			buf[i + 1] = ' ';
			return (1);
		}
		i += 3;
	}
	error_param(7);
	return (0);
}
