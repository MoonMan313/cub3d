/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:32:27 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:18:48 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	filling_map(char *line, char *map, int len)
{
	int	i;

	i = 0;
	while (i != len && line[i])
	{
		map[i] = line[i];
		i++;
	}
	while (i != len)
	{
		map[i] = ' ';
		i++;
	}
	map[i] = '\0';
}

int	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	check_extreme_line(char *line)
{
	while (*line && (*line == ' ' || *line == '1'))
		line++;
	if (*line != '\0')
		error_param(8);
}

void	check_char_map(t_cub *cub, int x, int y, int *p)
{
	if (check_player(cub->map[x][y]))
		*p += 1;
	if (cub->map[x][y -1] == ' ' || cub->map[x][y + 1] == ' '
		|| cub->map[x - 1][y] == ' ' || cub->map[x + 1][y] == ' ')
		error_param(8);
	if (cub->map[x][y] == '2')
		ft_lstadd_back(&cub->sprite, ft_lstnew(x, y));
}

void	parser_map(char **map, t_cub *cub)
{
	int		x;
	int		y;
	int		p;

	x = 1;
	p = 0;
	check_extreme_line(map[0]);
	while (map[x + 1] != 0)
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0' || map[x][y] == '2' || check_player(map[x][y]))
				check_char_map(cub, x, y, &p);
			y++;
		}
		x++;
	}
	check_extreme_line(map[x]);
	if (p != 1)
		error_param(6);
}
