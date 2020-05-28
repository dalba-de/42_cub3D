/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:10:38 by dalba-de          #+#    #+#             */
/*   Updated: 2020/03/04 11:19:38 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	pix_img(t_cub *cub, int color)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = cub->ray.x * (cub->bpp / 8) + cub->ray.l * cub->sizeline;
	while (i < (cub->bpp / 8))
	{
		cub->data[j + i] = color;
		color >>= 8;
		i++;
	}
}

int		draw(t_cub *cub)
{
	double	step;
	double	texpos;
	int		texy;
	int		color;

	cub->ray.l = -1;
	step = 1.0 * cub->text_h / cub->ray.lineheight;
	texpos = (cub->ray.drawstart - cub->height / 2 +
	cub->ray.lineheight / 2) * step;
	while (++cub->ray.l <= cub->ray.drawstart)
		pix_img(cub, cub->ceiling);
	while (++cub->ray.l <= cub->ray.drawend)
	{
		texy = (int)texpos & (cub->text_h - 1);
		texpos += step;
		color = cub->txt_data[cub->text_sl / 4 * texy + cub->text_x];
		pix_img(cub, color);
	}
	while (++cub->ray.l < cub->height)
		pix_img(cub, cub->floor);
	return (0);
}

void	check_x_text(t_cub *cub)
{
	cub->ray.wall_x -= floor(cub->ray.wall_x);
	cub->text_x = cub->ray.wall_x * (cub->text_sl / 4);
	if (cub->ray.side == 0 && cub->ray.x_dir > 0)
		cub->text_x = (cub->text_sl / 4) - cub->text_x - 1;
	if (cub->ray.side == 1 && cub->ray.y_dir < 0)
		cub->text_x = (cub->text_sl / 4) - cub->text_x - 1;
}

void	select_texture(t_cub *cub)
{
	if (cub->ray.walldir == 'N')
	{
		cub->txt_data = cub->txt[0].data;
		cub->text_sl = cub->txt[0].sl;
		cub->text_h = cub->txt[0].h;
	}
	if (cub->ray.walldir == 'S')
	{
		cub->txt_data = cub->txt[1].data;
		cub->text_sl = cub->txt[1].sl;
		cub->text_h = cub->txt[1].h;
	}
	if (cub->ray.walldir == 'E')
	{
		cub->txt_data = cub->txt[2].data;
		cub->text_sl = cub->txt[2].sl;
		cub->text_h = cub->txt[2].h;
	}
	if (cub->ray.walldir == 'W')
	{
		cub->txt_data = cub->txt[3].data;
		cub->text_sl = cub->txt[3].sl;
		cub->text_h = cub->txt[3].h;
	}
}

void	lengthline(t_cub *cub)
{
	cub->ray.lineheight = (int)(cub->height / cub->ray.walldist);
	cub->ray.drawstart = (cub->ray.lineheight * -1) / 2 + cub->height / 2;
	if (cub->ray.drawstart < 0)
		cub->ray.drawstart = 0;
	cub->ray.drawend = cub->ray.lineheight / 2 + cub->height / 2;
	if (cub->ray.drawend >= cub->height)
		cub->ray.drawend = cub->height - 1;
}
