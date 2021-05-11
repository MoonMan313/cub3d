/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:10:10 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:18:55 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	get_textures(t_tex *textur, t_cub *cub)
{
	textur->img = mlx_xpm_file_to_image(cub->mlx, textur->name, \
										&textur->width, &textur->height);
	if (textur->img == 0)
		error_param(5);
	textur->addr = mlx_get_data_addr(textur->img, &textur->bits_per_pixel, \
									&textur->line_length, &textur->endian);
	if (textur->addr == 0)
		error_param(5);
}

void	init_texture(t_tex *texture)
{
	texture->img = 0;
	texture->addr = 0;
	texture->bits_per_pixel = 0;
	texture->line_length = 0;
	texture->endian = 0;
	texture->height = 0;
	texture->width = 0;
	texture->tex_x = 0;
	texture->tex_y = 0;
	texture->step = 0;
	texture->tex_pos = 0;
}

void	color_conversion(t_cub *cub)
{
	cub->floor.all = 0 << 24 | cub->floor.red << 16 \
	| cub->floor.green << 8 | cub->floor.blue;
	cub->ceil.all = 0 << 24 | cub->ceil.red << 16 \
	| cub->ceil.green << 8 | cub->ceil.blue;
}
