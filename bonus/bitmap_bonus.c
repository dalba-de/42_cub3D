/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:18:47 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/08 18:39:38 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	write_color(int fd, unsigned char buffer[3])
{
	write(fd, &buffer[0], 1);
	write(fd, &buffer[1], 1);
	write(fd, &buffer[2], 1);
}

void	ft_zeropad(int fd, int len)
{
	int				i;
	unsigned char	c;

	c = 0x00;
	i = 0;
	while (i < len)
	{
		write(fd, &c, 1);
		i++;
	}
}

void	ft_data(t_cub *cub, int fd)
{
	int				x;
	int				y;
	unsigned char	buffer[3];
	unsigned int	color;
	char			*image;

	y = cub->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->width)
		{
			image = cub->data;
			image += (int)(y * cub->sizeline + (x * (cub->bpp / 8)));
			color = *(unsigned int *)image;
			buffer[0] = color % 256;
			buffer[1] = color / 256 % 256;
			buffer[2] = color / 256 / 256 % 256;
			write_color(fd, buffer);
			x++;
		}
		y--;
	}
}

void	header_write(t_cub *cub, int fd)
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	size;

	width = (unsigned int)cub->width;
	height = (unsigned int)cub->height;
	size = (3 * (width * height));
	size += ((width * 3) % 4) ? height * (4 - ((width * 3) % 4)) : 0;
	write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, "\x01\x00\x18\x00\x00\x00\x00\x00", 8);
	write(fd, &size, 4);
	ft_zeropad(fd, 16);
}

int		bitmap(t_cub *cub, char *argv)
{
	int fd;

	init_map(cub, argv);
	raycast(cub);
	draw_hud(cub);
	minimap(cub);
	draw_ammo(cub);
	draw_health(cub);
	draw_score(cub);
	draw_marine(cub);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	header_write(cub, fd);
	ft_data(cub, fd);
	close(fd);
	ft_close(cub);
	return (0);
}
