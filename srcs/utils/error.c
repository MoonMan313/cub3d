/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:45:29 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 18:12:10 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	error_param(int i)
{
	if (i == 1)
		printf("Error: color entered incorrectly\n");
	else if (i == 2)
		printf("Error: color entered more than once\n");
	else if (i == 3)
		printf("Error: display resolution specified incorrectly\n");
	else if (i == 4)
		printf("Error: texture entered more than once\n");
	else if (i == 5)
		printf("Error: texture entered incorrectly\n");
	else if (i == 6)
		printf("Error: the player's starting position is not correct\n");
	else if (i == 7)
		printf("Error: map parameters\n");
	else if (i == 8)
		printf("Error: map not valid\n");
	else if (i == 9)
		printf("Error: not enough memory\n");
	else if (i == 10)
		printf("Error: failed to create BMP file\n");
	else if (i == 11)
		printf("Error: first argument not valid\n");
	exit(1);
}

int	exita(int k)
{
	k = 0;
	exit(k);
	return (0);
}
