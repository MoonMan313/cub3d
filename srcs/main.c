/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:02:35 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 18:14:40 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

void	cub_init(t_cub *cub)
{
	cub->height = 0;
	cub->width = 0;
	cub->floor.blue = -1;
	cub->floor.green = -1;
	cub->floor.red = -1;
	cub->ceil.blue = -1;
	cub->ceil.green = -1;
	cub->ceil.red = -1;
	cub->no.name = 0;
	cub->so.name = 0;
	cub->we.name = 0;
	cub->ea.name = 0;
	cub->s.name = 0;
	cub->map_height = 0;
	cub->map_width = 0;
	cub->map = 0;
	cub->sprite = 0;
}

static void	read_map_1(int fd, t_cub *cub)
{
	char	*line;
	int		count;
	int		tmp;

	count = 0;
	tmp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (count < 8)
			count += first_check_map(line);
		else if (*line != '\0')
		{
			check_len_map_line(line, cub);
			count++;
		}
		free(line);
	}
	if (*line != '\0')
	{
		check_len_map_line(line, cub);
		count++;
	}
	free(line);
	cub->map_height = count - 8;
}

static void	read_map_2(int fd, t_cub *cub)
{
	char	*line;
	int		count;

	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (count < 8)
			count += parser_params_map(line, cub);
		else if (*line != '\0' && count == 8)
		{
			filling_map(line, cub->map[count - 8], cub->map_width);
			count++;
		}
		else if (count > 8 && cub->map_height > (count - 8))
		{
			if (*line == '\0')
				error_param(8);
			filling_map(line, cub->map[count - 8], cub->map_width);
			count++;
		}
		free(line);
	}
	if (*line != '\0')
		filling_map(line, cub->map[count - 8], cub->map_width);
	free(line);
}

void	parser(t_cub *cub, char *name_file)
{
	int		fd;

	check_file_cub(name_file);
	fd = open(name_file, O_RDONLY);
	read_map_1(fd, cub);
	close(fd);
	memory_allocation_map(cub);
	fd = open(name_file, O_RDONLY);
	read_map_2(fd, cub);
	close(fd);
	parser_map(cub->map, cub);
	color_conversion(cub);
	find_player(cub);
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
							&cub->line_length, &cub->endian);
}

int	main(int argc, char *argv[])
{
	t_cub	cub;

	if (argc == 2 || (argc == 3 && (ft_strlen(argv[2]) == 6) \
				&& (ft_strncmp(argv[2], "--save", 6) == 0)))
	{
		cub_init(&cub);
		cub.mlx = mlx_init();
		parser(&cub, argv[1]);
		if (argc == 2)
		{
			mlx_hook(cub.win, 2, 1L << 0, key_press, &cub);
			mlx_hook(cub.win, 17, 1L << 17, exita, &cub);
			mlx_loop_hook(cub.mlx, raycasting, &cub);
			mlx_loop(cub.mlx);
		}
		else
		{
			raycasting(&cub);
			make_screen(&cub);
		}
	}
	printf("Error: ivalid arguments\n");
	return (0);
}
