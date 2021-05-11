#include "../cub3.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		p[n] = 0;
}

void	header_file_bmp(t_cub *cub, int fd, int *padd_size)
{
	unsigned char	header[54];
	unsigned int	file_size;

	*padd_size = (4 - (cub->width * 3) % 4) % 4;
	file_size = 54 + (*padd_size + (cub->width * 3)) * cub->height;
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(file_size);
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)(cub->width);
	header[19] = (unsigned char)(cub->width >> 8);
	header[20] = (unsigned char)(cub->width >> 16);
	header[21] = (unsigned char)(cub->width >> 24);
	header[22] = (unsigned char)(cub->height);
	header[23] = (unsigned char)(cub->height >> 8);
	header[24] = (unsigned char)(cub->height >> 16);
	header[25] = (unsigned char)(cub->height >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	make_screen(t_cub *cub)
{
	int				i;
	int				fd;
	int				padd_size;
	unsigned char	zero[3];

	ft_bzero(zero, 3);
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG);
	if (fd == -1)
		error_param(10);
	header_file_bmp(cub, fd, &padd_size);
	cub->height--;
	while (cub->height >= 0)
	{
		i = 0;
		while (i < cub->width)
		{
			write(fd, &((int *)cub->addr)[cub->height * cub->width + i], 3);
			i++;
		}
		cub->height--;
		write(fd, zero, padd_size);
	}
	close(fd);
	exit(0);
}
