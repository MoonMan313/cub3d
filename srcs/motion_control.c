/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:40:33 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/12 15:46:52 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

void	step_d_a(t_cub *cub)
{
	if (cub->key.d)
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
	if (cub->key.a)
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

void	step_w_s(t_cub *cub)
{
	if (cub->key.w)
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
	if (cub->key.s)
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

int	check_key(t_cub *cub)
{
	if (cub->key.w || cub->key.s)
		step_w_s(cub);
	if (cub->key.d || cub->key.a)
		step_d_a(cub);
	if (cub->key.left)
		look_to_left(cub);
	if (cub->key.right)
		look_to_right(cub);
	return (0);
}
