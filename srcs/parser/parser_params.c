/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evelina <evelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:35:38 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/14 13:31:50 by evelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	parser_resolution(char *line, t_cub *cub)
{
	cub->width = ft_atoi(line);
	line = ft_isspase(line);
	line = ft_isdigit(line);
	cub->height = ft_atoi(line);
	line = ft_isspase(line);
	line = ft_isdigit(line);
	line = ft_isspase(line);
	if ((1 > cub->width) || (1 > cub->height) || *line != '\0')
		error_param(3);
	if ((cub->width > 1920) || (cub->height > 1080))
	{
		cub->width = 1920;
		cub->height = 1080;
	}
	cub->buf_distance = malloc(sizeof(double) * cub->width);
	if (!cub->buf_distance)
		error_param(9);
}

void	parser_color(char *line, t_color *color)
{
	if (color->red != -1 && color->green != -1 && color->blue != -1)
		error_param(2);
	color->red = ft_atoi(line);
	line = pass_for_atoi(line);
	color->green = ft_atoi(line);
	line = pass_for_atoi(line);
	color->blue = ft_atoi(line);
	line = ft_isspase(line);
	line = ft_isdigit(line);
	line = ft_isspase(line);
	if ((color->red < 0) || (color->red > 255) || (color->green < 0) \
	|| (color->green > 255) || (color->blue < 0) || (color->blue > 255) \
	|| *line != '\0')
		error_param(1);
}

void	parser_texture(char *line, t_tex *texture, t_cub *cub)
{
	if (texture->name != 0)
		error_param(4);
	if (line[0] != ' ')
		error_param(5);
	line = ft_isspase(line);
	texture->name = ft_strdup(line);
	init_texture(texture);
	get_textures(texture, cub);
}

int	parser_params_map(char *line, t_cub *cub)
{
	line = ft_isspase(line);
	if (*line == 'R')
		parser_resolution((line + 1), cub);
	else if (*line == 'N' && *(line + 1) == 'O')
		parser_texture((line + 2), &cub->no, cub);
	else if (*line == 'S' && *(line + 1) == 'O')
		parser_texture((line + 2), &cub->so, cub);
	else if (*line == 'W' && *(line + 1) == 'E')
		parser_texture((line + 2), &cub->we, cub);
	else if (*line == 'E' && *(line + 1) == 'A')
		parser_texture((line + 2), &cub->ea, cub);
	else if (*line == 'S')
		parser_texture((line + 1), &cub->s, cub);
	else if (*line == 'F')
		parser_color((line + 1), &cub->floor);
	else if (*line == 'C')
		parser_color((line + 1), &cub->ceil);
	else
		return (0);
	return (1);
}
