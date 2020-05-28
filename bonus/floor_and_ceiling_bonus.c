/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:50:08 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/10 17:38:04 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	draw_sky(t_cub *cub)
{
	int					sky_y;
	int					sky_y_img;

	sky_y = 0;
	sky_y_img = 0;
	while (sky_y < cub->ray.drawstart)
	{
		if (cub->txt[10].h <= sky_y_img)
			sky_y_img = 0;
		draw_dot(cub, cub->ray.x, sky_y, cub->txt[10].data
		[cub->ray.x + sky_y_img * cub->txt[10].sl / 4]);
		sky_y++;
		sky_y_img++;
	}
}

void	draw_floor(t_cub *cub)
{
	t_txt	*img;

	if (cub->level == 1)
		img = &cub->txt[6];
	else
		img = &cub->txt[18];
	cub->f.cellx = (int)cub->f.floorx;
	cub->f.celly = (int)cub->f.floory;
	cub->f.tx = (int)(64 * (cub->f.floorx - cub->f.cellx)) & (64 - 1);
	cub->f.ty = (int)(64 * (cub->f.floory - cub->f.celly)) & (64 - 1);
	cub->f.floorx += cub->f.stepx;
	cub->f.floory += cub->f.stepy;
	draw_dot(cub, cub->f.x, cub->f.y,
	img->data[img->w * cub->f.tx + cub->f.ty]);
	if (cub->level == 1)
		draw_dot(cub, cub->f.x, cub->height - cub->f.y,
		cub->txt[8].data[cub->txt[8].w * cub->f.tx + cub->f.ty]);
}

void	floor_casting(t_cub *cub)
{
	cub->f.y = 0;
	while (cub->f.y < cub->height)
	{
		cub->f.raydirx0 = cub->ray.x_dir - cub->ray.x_plane;
		cub->f.raydiry0 = cub->ray.y_dir - cub->ray.y_plane;
		cub->f.raydirx1 = cub->ray.x_dir + cub->ray.x_plane;
		cub->f.raydiry1 = cub->ray.y_dir + cub->ray.y_plane;
		cub->f.p = cub->f.y - cub->height / 2;
		cub->f.posz = 0.5 * cub->height;
		cub->f.rowdistance = cub->f.posz / cub->f.p;
		cub->f.stepx = cub->f.rowdistance *
		(cub->f.raydirx1 - cub->f.raydirx0) / cub->width;
		cub->f.stepy = cub->f.rowdistance *
		(cub->f.raydiry1 - cub->f.raydiry0) / cub->width;
		cub->f.floorx = cub->ray.x_pos + cub->f.rowdistance * cub->f.raydirx0;
		cub->f.floory = cub->ray.y_pos + cub->f.rowdistance * cub->f.raydiry0;
		cub->f.x = 0;
		while (cub->f.x < cub->width)
		{
			draw_floor(cub);
			cub->f.x++;
		}
		cub->f.y++;
	}
}
