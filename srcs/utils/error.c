/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:45:29 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 20:05:00 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	error_param(int i)
{
	if (i == 1)
		printf("Error\ncolor entered incorrectly\n");
	else if (i == 2)
		printf("Error\ncolor entered more than once\n");
	else if (i == 3)
		printf("Error\ndisplay resolution specified incorrectly\n");
	else if (i == 4)
		printf("Error\ntexture entered more than once\n");
	else if (i == 5)
		printf("Error\ntexture entered incorrectly\n");
	else if (i == 6)
		printf("Error\nthe player's starting position is not correct\n");
	else if (i == 7)
		printf("Error\nmap parameters\n");
	else if (i == 8)
		printf("Error\nmap not valid\n");
	else if (i == 9)
		printf("Error\nnot enough memory\n");
	else if (i == 10)
		printf("Error\nfailed to create BMP file\n");
	else if (i == 11)
		printf("Error\nfirst argument not valid\n");
	exit(1);
}

int	exita(int k)
{
	k = 0;
	exit(k);
	return (0);
}
