/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:04:58 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 18:17:12 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <unistd.h>
# include <stdlib.h>
# include "./mlx_linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

/* Keyboard keys */
// # define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2
// # define LEFT 123
// # define RIGHT 124

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

/* Parameters */
# define STEP 0.05
# define P 0.025

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	all;
}				t_color;

typedef struct s_tex
{
	char	*name;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}				t_tex;

typedef struct s_list
{
	int				x;
	int				y;
	double			distance;
	struct s_list	*next;
}				t_list;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}				t_key;

typedef struct s_cub
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	start_x;
	double	start_y;
	t_key	key;
	int		flag;
	double	*buf_distance;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_color	floor;
	t_color	ceil;
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
	t_tex	s;
	t_list	*sprite;
	char	**map;
	int		map_width;
	int		map_height;
	char	dir_player;

}				t_cub;

typedef struct s_ray
{
	int		line_height;
	int		x;
	int		map_x;
	int		map_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		draw_start;
	int		draw_end;
	double	wall;

}				t_ray;

typedef struct s_sprite
{
	int		x;
	int		y;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		spriteWidth;
	int		drawStartX;
	int		drawStartY;
	int		drawEndX;
	int		drawEndY;
}				t_sprite;

void			color_conversion(t_cub *cub);
void			error_param(int i);
int				parser_params_map(char *line, t_cub *cub);
int				first_check_map(char *line);
int				check_len_map_line(char *line, t_cub *cub);
int				get_next_line(int fd, char **line);
int				get_buf(char **g_buf, char **g_line);
char			*line_join(char *dst, char *src, int len);
int				ft_strn(char *s);
int				ft_strlen(char *s);
char			*ft_strdup(char *s1);
void			parser_resolution(char *line, t_cub *cub);
void			parser_color(char *line, t_color *color);
void			parser_texture(char *line, t_tex *texture, t_cub *cub);
char			*ft_isspase(const char *s);
char			*ft_isdigit(const char *s);
char			*pass_for_atoi(const char *line);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			memory_allocation_map(t_cub *cub);
void			filling_map(char *line, char *map, int len);
void			parser_map(char **map, t_cub *cub);
int				check_player(char c);
int				show_map(t_cub *img);
int				key_press(int key, t_cub *cub);
int				exita(int k);
void			my_mlx_pixel_put(t_cub *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_tex *data, int x, int y);
void			find_player(t_cub *cub);
int				raycasting(t_cub *cub);
void			direction(t_cub *cub);
void			look_to_left(t_cub *cub);
void			look_to_right(t_cub *cub);
void			get_textures(t_tex *textur, t_cub *cub);
void			init_texture(t_tex *textur);
void			wall_size(t_ray *ray, t_cub *cub);
void			draw_line(t_ray *ray, t_cub *cub);
void			draw_wall(t_ray *ray, t_cub *cub, t_tex *textur, int *y);
t_list			*ft_lstnew(int x, int y);
void			ft_lstadd_back(t_list **lst, t_list *list);
void			find_sprite(t_cub *cub);
void			draw_sprite( t_cub *cub, t_list *list);
void			sort_sprite(t_cub *cub);
void			make_screen(t_cub *cub);
void			setting_sprite_param(t_sprite *sprite, t_cub *cub, \
				int spr_x, int spr_y);
void			check_file_cub(char *name);
int				check_key(t_cub *cub);
int				releasing_key(int key, t_cub *cub);

#endif
