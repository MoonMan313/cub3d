/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evelina <evelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:13:37 by evelina           #+#    #+#             */
/*   Updated: 2021/05/13 21:14:24 by evelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		cub->key.w = 1;
	else if (key == S)
		cub->key.s = 1;
	else if (key == D)
		cub->key.d = 1;
	else if (key == A)
		cub->key.a = 1;
	else if (key == LEFT)
		cub->key.left = 1;
	else if (key == RIGHT)
		cub->key.right = 1;
	return (0);
}

int	releasing_key(int key, t_cub *cub)
{
	if (key == W)
		cub->key.w = 0;
	else if (key == S)
		cub->key.s = 0;
	else if (key == D)
		cub->key.d = 0;
	else if (key == A)
		cub->key.a = 0;
	else if (key == LEFT)
		cub->key.left = 0;
	else if (key == RIGHT)
		cub->key.right = 0;
	return (0);
}
