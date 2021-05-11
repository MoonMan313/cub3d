/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:40:33 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:17:50 by cdionna          ###   ########.fr       */
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

void	look_to_left(t_cub *cub)
{
	double	tmp;

	tmp = cub->dir_x;
	cub->dir_x = tmp * cos(0.1) - cub->dir_y * sin(0.1);
	cub->dir_y = tmp * sin(0.1) + cub->dir_y * cos(0.1);
	tmp = cub->plane_x;
	cub->plane_x = tmp * cos(0.1) - cub->plane_y * sin(0.1);
	cub->plane_y = tmp * sin(0.1) + cub->plane_y * cos(0.1);
}

void	look_to_right(t_cub *cub)
{
	double	tmp;

	tmp = cub->dir_x;
	cub->dir_x = tmp * cos(-0.1) - cub->dir_y * sin(-0.1);
	cub->dir_y = tmp * sin(-0.1) + cub->dir_y * cos(-0.1);
	tmp = cub->plane_x;
	cub->plane_x = tmp * cos(-0.1) - cub->plane_y * sin(-0.1);
	cub->plane_y = tmp * sin(-0.1) + cub->plane_y * cos(-0.1);
}
