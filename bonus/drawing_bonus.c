/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:10:38 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/10 17:17:34 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

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

	cub->ray.l = cub->ray.drawstart - 1;
	step = 1.0 * cub->text_h / cub->ray.lineheight;
	texpos = (cub->ray.drawstart - cub->height / 2 +
	cub->ray.lineheight / 2) * step;
	while (++cub->ray.l <= cub->ray.drawend)
	{
		texy = (int)texpos & (cub->text_h - 1);
		texpos += step;
		color = cub->txt_data[cub->text_sl / 4 * texy + cub->text_x];
		pix_img(cub, color);
	}
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
	north_text(cub);
	south_text(cub);
	east_text(cub);
	west_text(cub);
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
