/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:08:59 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/08 19:29:59 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

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

void	sprite_shot(t_cub *cub)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	while (i < cub->map_spr)
	{
		if (cub->spr[cub->sprorder[i]].c == 'B')
		{
			x = cub->spr[cub->sprorder[i]].x - cub->ray.x_pos;
			y = cub->spr[cub->sprorder[i]].y - cub->ray.y_pos;
			if (x >= -4 && x <= 4 && y >= -4 && y <= 4)
			{
				cub->spr[cub->sprorder[i]].v += 1;
				get_shot(cub, &cub->spr[cub->sprorder[i]]);
			}
			else
			{
				if (cub->level == 2)
					cub->spr[cub->sprorder[i]].getshot = 0;
				i++;
			}
		}
		i++;
	}
}

void	sprite_parser(t_cub *cub, t_spr spr_ptr, t_sprtools stools, int i)
{
	t_txt *img;

	if (spr_ptr.c == '2')
		img = &cub->txt[4];
	else if (spr_ptr.c == 'T')
		img = &cub->txt[5];
	else if (spr_ptr.c == 'M')
		img = &cub->enemy[2];
	else if (spr_ptr.c == 'H')
		img = &cub->txt[14];
	else if (spr_ptr.c == '3')
		img = &cub->txt[15];
	else if (spr_ptr.c == '4')
		img = &cub->txt[16];
	else if (spr_ptr.c == '5')
		img = &cub->txt[17];
	else if (spr_ptr.c == 'B')
	{
		if (cub->level == 1)
			cub->spr[cub->sprorder[i]].getshot = 0;
		cub->sp_state = anim_text(&spr_ptr);
		draw_sprite_enemy(&stools, cub, i);
		return ;
	}
	draw_sprite(&stools, cub, img);
}

void	ft_sprite(t_cub *cub)
{
	int			i;
	t_sprtools	stools;
	t_spr		spr_ptr;

	sort_sprites(cub);
	sprite_shot(cub);
	i = 0;
	while (i < cub->map_spr)
	{
		spr_ptr = cub->spr[cub->sprorder[i]];
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
		sprite_parser(cub, spr_ptr, stools, i);
		i++;
	}
}
