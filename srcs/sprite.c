/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:50:48 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:18:03 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

void	find_sprite(t_cub *cub)
{
	t_list	*list;

	list = cub->sprite;
	while (list)
	{
		draw_sprite(cub, list);
		list = list->next;
	}
}

void	swap_list(t_list *first, t_list *second)
{
	int		x;
	int		y;
	double	dist;

	if (first != NULL && second != NULL)
	{
		x = first->x;
		y = first->y;
		dist = first->distance;
		first->x = second->x;
		first->y = second->y;
		first->distance = second->distance;
		second->x = x;
		second->y = y;
		second->distance = dist;
	}
}

void	sort(t_cub *cub)
{
	t_list	*start;
	t_list	*next;
	int		unsorted;

	start = cub->sprite;
	unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		cub->sprite = start;
		while (cub->sprite != NULL && cub->sprite->next != NULL)
		{
			next = cub->sprite->next;
			if (next->distance > cub->sprite->distance)
			{
				swap_list(cub->sprite, next);
				unsorted = 1;
			}
			cub->sprite = next;
		}
	}
	cub->sprite = start;
	find_sprite(cub);
}

void	sort_sprite(t_cub *cub)
{
	t_list	*list;

	list = cub->sprite;
	while (cub->sprite)
	{
		cub->sprite->distance = ((cub->start_x - cub->sprite->x) * \
		(cub->start_x - cub->sprite->x) + (cub->start_y - cub->sprite->y) \
		* (cub->start_y - cub->sprite->y));
		cub->sprite = cub->sprite->next;
	}
	cub->sprite = list;
	sort(cub);
}

void	draw_sprite(t_cub *cub, t_list *list)
{
	t_sprite		sprite;
	unsigned int	color;

	setting_sprite_param(&sprite, cub, list->x, list->y);
	sprite.x = sprite.drawStartX;
	while (sprite.x < sprite.drawEndX)
	{
		sprite.y = sprite.drawStartY;
		cub->s.tex_x = (int)((sprite.x - (-sprite.spriteWidth / 2 + sprite.spriteScreenX)) \
		* cub->s.width / sprite.spriteWidth);
		if (sprite.transformY > 0 && sprite.x > 0 && sprite.x < cub->width \
			&& sprite.transformY < cub->buf_distance[sprite.x])
		{
			while (sprite.y < sprite.drawEndY)
			{
				cub->s.tex_y = (((sprite.y - cub->height * 0.5 + sprite.spriteHeight * 0.5) \
					* cub->s.height) / sprite.spriteHeight);
				color = my_mlx_pixel_get(&cub->s, cub->s.tex_x, cub->s.tex_y);
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(cub, sprite.x, sprite.y, color);
				sprite.y++;
			}
		}
		sprite.x++;
	}
}
