/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evelina <evelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:40:33 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/14 17:26:32 by evelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

void	step_d_a(int key, t_cub *cub)
{
	if (key == D)
	{
		if (cub->map[(int)(cub->start_x + cub->dir_y * STEP)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y - cub->dir_x * STEP)] != '1')
		{
			cub->start_x += cub->dir_y * STEP;
			cub->start_y -= cub->dir_x * STEP;
		}
	}
	else
	{
		if (cub->map[(int)(cub->start_x - cub->dir_y * STEP)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y + cub->dir_x * STEP)] != '1')
		{
			cub->start_x -= cub->dir_y * STEP;
			cub->start_y += cub->dir_x * STEP;
		}
	}
}

void	step_w_s(int key, t_cub *cub)
{
	if (key == W)
	{
		if (cub->map[(int)(cub->start_x + cub->dir_x * STEP)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y + cub->dir_y * STEP)] != '1')
		{
			cub->start_x += cub->dir_x * STEP;
			cub->start_y += cub->dir_y * STEP;
		}
	}
	else
	{
		if (cub->map[(int)(cub->start_x - cub->dir_x * STEP)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y - cub->dir_y * STEP)] != '1')
		{
			cub->start_x -= cub->dir_x * STEP;
			cub->start_y -= cub->dir_y * STEP;
		}
	}
}

void	look_to_left(t_cub *cub)
{
	double	tmp;

	tmp = cub->dir_x;
	cub->dir_x = tmp * cos(P) - cub->dir_y * sin(P);
	cub->dir_y = tmp * sin(P) + cub->dir_y * cos(P);
	tmp = cub->plane_x;
	cub->plane_x = tmp * cos(P) - cub->plane_y * sin(P);
	cub->plane_y = tmp * sin(P) + cub->plane_y * cos(P);
}

void	look_to_right(t_cub *cub)
{
	double	tmp;

	tmp = cub->dir_x;
	cub->dir_x = tmp * cos(-P) - cub->dir_y * sin(-P);
	cub->dir_y = tmp * sin(-P) + cub->dir_y * cos(-P);
	tmp = cub->plane_x;
	cub->plane_x = tmp * cos(-P) - cub->plane_y * sin(-P);
	cub->plane_y = tmp * sin(-P) + cub->plane_y * cos(-P);
}

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
	else if (key == W || key == S)
		step_w_s(key, cub);
	else if (key == D || key == A)
		step_d_a(key, cub);
	else if (key == LEFT)
		look_to_left(cub);
	else if (key == RIGHT)
		look_to_right(cub);
	return (0);
}
