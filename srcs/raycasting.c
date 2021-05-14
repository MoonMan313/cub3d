/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evelina <evelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:18:41 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/14 18:58:26 by evelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

void	wall_collision_detection(t_ray *ray, t_cub *cub)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			if (ray->step_x < 0)
				cub->flag = 1;
			else
				cub->flag = 0;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			if (ray->step_y < 0)
				cub->flag = 1;
			else
				cub->flag = 0;
			ray->side = 1;
		}
		if (cub->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	side_from_ray(t_ray *ray, double x, double y)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - y) * ray->delta_y;
	}
}

void	ray_of_setting(t_ray *ray, t_cub *cub)
{
	double	camera_x;

	ray->hit = 0;
	ray->map_x = (int)cub->start_x;
	ray->map_y = (int)cub->start_y;
	camera_x = 2 * ray->x / (double)cub->width - 1;
	ray->ray_dir_x = cub->dir_x + cub->plane_x * camera_x;
	ray->ray_dir_y = cub->dir_y + cub->plane_y * camera_x;
	if (ray->ray_dir_y == 0)
		ray->delta_x = 0;
	else if (ray->ray_dir_x == 0)
		ray->delta_x = 1;
	else
		ray->delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->delta_y = 0;
	else if (ray->ray_dir_y == 0)
		ray->delta_y = 1;
	else
		ray->delta_y = fabs(1 / ray->ray_dir_y);
}

int	raycasting(t_cub *cub)
{
	t_ray	ray;

	ray.x = 0;
	check_key(cub);
	while (ray.x < cub->width)
	{
		ray_of_setting(&ray, cub);
		side_from_ray(&ray, cub->start_x, cub->start_y);
		wall_collision_detection(&ray, cub);
		wall_size(&ray, cub);
		draw_line(&ray, cub);
		cub->buf_distance[ray.x] = ray.wall_dist;
		ray.x++;
	}
	sort_sprite(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}
