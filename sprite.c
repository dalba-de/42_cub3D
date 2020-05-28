/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:08:59 by dalba-de          #+#    #+#             */
/*   Updated: 2020/03/04 11:20:24 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw_dot(t_cub *cub, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (cub->sizeline * y) + (x * (cub->bpp / 8));
	cub->data[i] = b;
	cub->data[i + 1] = g;
	cub->data[i + 2] = r;
}

void	draw_sprite(t_sprtools *stools, t_cub *cub)
{
	stools->x = stools->drawstart_x;
	while (stools->x < stools->drawend_x)
	{
		stools->tex_x = (int)((stools->x - ((-1 * stools->width) /
		2 + stools->screen)) * cub->txt[4].w / stools->width);
		if (stools->transf_y > 0 && stools->x >= 0 && stools->x
		< cub->width && stools->transf_y < cub->zbuffer[stools->x])
		{
			stools->y = stools->drawstart_y;
			while (stools->y < stools->drawend_y)
			{
				stools->d = stools->y * 256 - cub->height * 128 +
				stools->height * 128;
				stools->tex_y = ((stools->d * cub->txt[4].h) /
				stools->height) / 256;
				if (*(cub->txt[4].data + stools->tex_x + stools->tex_y
				* cub->txt[4].sl / 4))
					draw_dot(cub, stools->x, stools->y,
					cub->txt[4].data[stools->tex_x +
					stools->tex_y * cub->txt[4].sl / 4]);
				stools->y++;
			}
		}
		stools->x++;
	}
}

void	sprite_space(t_sprtools *stools, t_cub *cub)
{
	stools->drawstart_y = 0;
	stools->height = abs((int)(cub->height / (stools->transf_y)));
	stools->drawstart_y = (-1 * stools->height) / 2 + cub->height / 2;
	if (stools->drawstart_y < 0)
		stools->drawstart_y = 0;
	stools->drawend_y = stools->height / 2 + cub->height / 2;
	if (stools->drawend_y >= cub->height)
		stools->drawend_y = cub->height - 1;
	stools->width = abs((int)(cub->height / (stools->transf_y)));
	stools->drawstart_x = (-1 * stools->width) / 2 + stools->screen;
	if (stools->drawstart_x < 0)
		stools->drawstart_x = 0;
	stools->drawend_x = stools->width / 2 + stools->screen;
	if (stools->drawend_x >= cub->width)
		stools->drawend_x = cub->width - 1;
}

void	sort_sprites(t_cub *cub)
{
	int tmp_d;
	int tmp_o;
	int i;

	i = -1;
	while (++i < cub->map_spr)
	{
		cub->spr[i].d = pow((cub->ray.x_pos - cub->spr[i].x), 2) +
		pow((cub->ray.y_pos - cub->spr[i].y), 2);
		cub->sprorder[i] = i;
	}
	i = -1;
	while (++i < cub->map_spr - 1)
	{
		if (cub->spr[i].d < cub->spr[i + 1].d)
		{
			tmp_d = cub->spr[i].d;
			cub->spr[i].d = cub->spr[i + 1].d;
			cub->spr[i + 1].d = tmp_d;
			tmp_o = cub->sprorder[i];
			cub->sprorder[i] = cub->sprorder[i + 1];
			cub->sprorder[i + 1] = tmp_o;
			i = -1;
		}
	}
}

void	ft_sprite(t_cub *cub)
{
	int			i;
	t_sprtools	stools;
	t_spr		spr_ptr;

	sort_sprites(cub);
	i = 0;
	while (i < cub->map_spr)
	{
		spr_ptr = cub->spr[cub->sprorder[i++]];
		stools.sp_x = (spr_ptr.x) - cub->ray.x_pos;
		stools.sp_y = (spr_ptr.y) - cub->ray.y_pos;
		stools.invdet = 1.0 / (cub->ray.x_plane * cub->ray.y_dir
		- cub->ray.x_dir * cub->ray.y_plane);
		stools.transf_x = stools.invdet * (cub->ray.y_dir *
		stools.sp_x - cub->ray.x_dir * stools.sp_y);
		stools.transf_y = stools.invdet * (-cub->ray.y_plane *
		stools.sp_x + cub->ray.x_plane * stools.sp_y);
		stools.screen = (int)(cub->width / 2) * (1 +
		stools.transf_x / stools.transf_y);
		sprite_space(&stools, cub);
		draw_sprite(&stools, cub);
	}
}
