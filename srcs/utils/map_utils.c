/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:04:15 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 18:12:26 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	memory_allocation_map(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->map_width < 3 || cub->map_height < 3)
		error_param(8);
	cub->map = (char **)malloc((cub->map_height + 1) * sizeof(char *));
	if (!cub->map)
		error_param(9);
	while (i != cub->map_height)
	{
		cub->map[i] = (char *)malloc((cub->map_width + 1) * sizeof(char));
		if (!cub->map[i])
			error_param(9);
		i++;
	}
	cub->map[i] = 0;
}

void	find_player(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (cub->map[x] != 0)
	{
		y = 0;
		while (cub->map[x][y] != 0)
		{
			if (check_player(cub->map[x][y]))
			{
				cub->start_y = y + 0.5;
				cub->start_x = x + 0.5;
				cub->dir_player = cub->map[x][y];
				cub->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
	direction(cub);
}

void	direction(t_cub *cub)
{
	int	n;

	n = 1;
	if (cub->dir_player == 'S' || cub->dir_player == 'W')
		n = -1;
	if (cub->dir_player == 'N' || cub->dir_player == 'S')
	{
		cub->dir_x = -1 * n;
		cub->dir_y = 0 ;
		cub->plane_x = 0;
		cub->plane_y = 0.66 * n;
	}
	else
	{
		cub->dir_x = 0;
		cub->dir_y = 1 * n;
		cub->plane_x = 0.66 * n;
		cub->plane_y = 0;
	}
}

void	check_file_cub(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
		++i;
	i--;
	if (!(i > 4 && name[i] == 'b' && name[i - 1] == 'u' \
			&& name[i - 2] == 'c' && name[i - 3] == '.'))
		error_param (11);
}
