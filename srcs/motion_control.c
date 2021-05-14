/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evelina <evelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:40:33 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/14 19:31:08 by evelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

void	step_d_a(t_cub *cub, double step)
{
	if (cub->key.d)
	{
		if (cub->map[(int)(cub->start_x + cub->dir_y * step)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y - cub->dir_x * step)] != '1')
		{
			cub->start_x += cub->dir_y * step;
			cub->start_y -= cub->dir_x * step;
		}
	}
	if (cub->key.a)
	{
		if (cub->map[(int)(cub->start_x - cub->dir_y * step)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y + cub->dir_x * step)] != '1')
		{
			cub->start_x -= cub->dir_y * step;
			cub->start_y += cub->dir_x * step;
		}
	}
}

void	step_w_s(t_cub *cub, double step)
{
	if (cub->key.w)
	{
		if (cub->map[(int)(cub->start_x + cub->dir_x * step)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y + cub->dir_y * step)] != '1')
		{
			cub->start_x += cub->dir_x * step;
			cub->start_y += cub->dir_y * step;
		}
	}
	if (cub->key.s)
	{
		if (cub->map[(int)(cub->start_x - cub->dir_x * step)] \
		[(int)cub->start_y] != '1'
		&& cub->map[(int)cub->start_x] \
		[(int)(cub->start_y - cub->dir_y * step)] != '1')
		{
			cub->start_x -= cub->dir_x * step;
			cub->start_y -= cub->dir_y * step;
		}
	}
}

void	look_to_left(t_cub *cub, double grad)
{
	double	tmp;

	tmp = cub->dir_x;
	cub->dir_x = tmp * cos(grad) - cub->dir_y * sin(grad);
	cub->dir_y = tmp * sin(grad) + cub->dir_y * cos(grad);
	tmp = cub->plane_x;
	cub->plane_x = tmp * cos(grad) - cub->plane_y * sin(grad);
	cub->plane_y = tmp * sin(grad) + cub->plane_y * cos(grad);
}

void	look_to_right(t_cub *cub, double grad)
{
	double	tmp;

	tmp = cub->dir_x;
	cub->dir_x = tmp * cos(-grad) - cub->dir_y * sin(-grad);
	cub->dir_y = tmp * sin(-grad) + cub->dir_y * cos(-grad);
	tmp = cub->plane_x;
	cub->plane_x = tmp * cos(-grad) - cub->plane_y * sin(-grad);
	cub->plane_y = tmp * sin(-grad) + cub->plane_y * cos(-grad);
}

int	check_key(t_cub *cub)
{
	double	step;
	double	grad;

	step = (double)(cub->width * cub->height) / 25000000;
	grad = (double)(cub->width * cub->height) / 50000000;
	if (cub->key.w || cub->key.s)
		step_w_s(cub, step);
	if (cub->key.d || cub->key.a)
		step_d_a(cub, step);
	if (cub->key.left)
		look_to_left(cub, grad);
	if (cub->key.right)
		look_to_right(cub, grad);
	return (0);
}
