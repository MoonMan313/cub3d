/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:00:44 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 18:33:31 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	draw_wall(t_ray *ray, t_cub *cub, t_tex *texture, int *y)
{
	unsigned int	color;

	texture->tex_x = (int)(ray->wall * (double)texture->width);
	texture->step = 1.0 * texture->height / ray->line_height;
	texture->tex_pos = (ray->draw_start - cub->height / 2 + \
						ray->line_height / 2) * texture->step;
	while (*y >= ray->draw_start && *y < ray->draw_end \
			&& *y != cub->height - 1)
	{
		texture->tex_y = (int)texture->tex_pos;
		texture->tex_pos += texture->step;
		color = my_mlx_pixel_get(texture, texture->tex_x, texture->tex_y);
		my_mlx_pixel_put(cub, ray->x, *y, color);
		*y += 1;
	}
}

void	draw_line(t_ray *ray, t_cub *cub)
{
	int	y;

	y = 0;
	while (y != cub->height)
	{
		if (y < ray->draw_start)
			my_mlx_pixel_put(cub, ray->x, y, cub->floor.all);
		if (y == ray->draw_start)
		{
			if (ray->side == 0 && cub->flag == 1)
				draw_wall(ray, cub, &cub->no, &y);
			else if (ray->side == 0 && cub->flag == 0)
				draw_wall(ray, cub, &cub->so, &y);
			else if (ray->side == 1 && cub->flag == 1)
				draw_wall(ray, cub, &cub->we, &y);
			else
				draw_wall(ray, cub, &cub->ea, &y);
		}
		if (y >= ray->draw_end)
			my_mlx_pixel_put(cub, ray->x, y, cub->ceil.all);
		if (y != cub->height)
			y++;
	}
}

void	wall_size(t_ray *ray, t_cub *cub)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - cub->start_x + \
		(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->wall_dist = (ray->map_y - cub->start_y + \
		(1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->wall_dist == 0)
		ray->line_height = cub->height;
	else
		ray->line_height = (int)(cub->height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + cub->height / 2;
	ray->draw_end = ray->line_height / 2 + cub->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= cub->height)
		ray->draw_end = cub->height - 1;
	if (ray->side == 0)
		ray->wall = cub->start_y + ray->wall_dist * ray->ray_dir_y;
	else
		ray->wall = cub->start_x + ray->wall_dist * ray->ray_dir_x;
	ray->wall -= floor((ray->wall));
}
