/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evelina <evelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:41:31 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/14 13:39:45 by evelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	define_sprite_boundaries(t_sprite *sprite, t_cub *cub)
{
	sprite->drawStartY = -sprite->spriteHeight / 2 + cub->height / 2;
	if (sprite->drawStartY < 0)
		sprite->drawStartY = 0;
	sprite->drawEndY = sprite->spriteHeight / 2 + cub->height / 2;
	if (sprite->drawEndY >= cub->height)
		sprite->drawEndY = cub->height - 1;
	sprite->drawStartX = -sprite->spriteWidth / 2 + sprite->spriteScreenX;
	if (sprite->drawStartX < 0)
		sprite->drawStartX = 0;
	sprite->drawEndX = sprite->spriteWidth / 2 + sprite->spriteScreenX;
	if (sprite->drawEndX >= cub->width)
		sprite->drawEndX = cub->width - 1;
}

void	setting_sprite_param(t_sprite *sprite, t_cub *cub, int spr_x, int spr_y)
{
	double	invDet;

	invDet = 1.0 / (cub->plane_x * cub->dir_y - cub->dir_x * cub->plane_y);
	sprite->transformX = invDet * (cub->dir_y * (spr_x - cub->start_x + 0.5) \
								- cub->dir_x * (spr_y - cub->start_y + 0.5));
	sprite->transformY = invDet * (-cub->plane_y * (spr_x - cub->start_x + 0.5) \
								+ cub->plane_x * (spr_y - cub->start_y + 0.5));
	sprite->spriteScreenX = (int)((cub->width / 2) * (1 + sprite->transformX \
										/ sprite->transformY));
	sprite->spriteHeight = abs((int)(cub->height / (sprite->transformY)));
	sprite->spriteWidth = abs((int)(cub->height / (sprite->transformY)));
	define_sprite_boundaries(sprite, cub);
}
