/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:11:20 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 17:29:38 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	draw_health(t_cub *cub)
{
	t_health	h;

	h.frame = 0;
	h.life = cub->life;
	while (h.life >= 0)
	{
		h.health = h.life % 10;
		h.i = 0;
		h.x = 15 * h.health;
		while (h.x < 15 * (h.health + 1))
		{
			h.y = 0;
			while (h.y++ < 17)
				if (*(cub->numeros.data + h.x + h.y * cub->numeros.sl / 4))
					draw_square(cub, (cub->height - 30 - cub->numeros.h
					* 2.5) + h.y * 2.5, (230 - h.frame) + h.i * 2.5,
					cub->numeros.data[h.x + h.y * cub->numeros.sl / 4]);
			h.i++;
			h.x++;
		}
		h.frame += 40;
		h.life /= 10;
		if (h.life == 0)
			h.life = -1;
	}
}

void	draw_num_bullet(t_cub *cub)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 15 * cub->ammo;
	while (x < 15 * (cub->ammo + 1))
	{
		y = 0;
		while (y < 17)
		{
			if (*(cub->numeros.data + x + y * cub->numeros.sl / 4))
				draw_square(cub, (cub->height - 40 - cub->numeros.h)
				+ y, 120 + i,
				cub->numeros.data[x + y * cub->numeros.sl / 4]);
			y++;
		}
		i++;
		x++;
	}
}

void	draw_ic_knife(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	while (x < 43)
	{
		y = 0;
		while (y < 13)
		{
			if (*(cub->txt[12].data + x + y * cub->txt[12].sl / 4))
				draw_square(cub, (cub->height - 40 - cub->txt[12].h
				* 2) + y * 2, 10 + x * 2.5,
				cub->txt[12].data[x + y * cub->txt[12].sl / 4]);
			y++;
		}
		x++;
	}
}

void	draw_ammo(t_cub *cub)
{
	int x;
	int y;

	if (cub->ammo == 0)
		draw_ic_knife(cub);
	else if (cub->ammo > 0)
	{
		draw_num_bullet(cub);
		x = 0;
		while (x < 38)
		{
			y = 0;
			while (y < 17)
			{
				if (*(cub->txt[13].data + x + y * cub->txt[13].sl / 4))
					draw_square(cub, (cub->height - 35 - cub->txt[13].h
					* 2) + y * 2, 10 + x * 2.5,
					cub->txt[13].data[x + y * cub->txt[13].sl / 4]);
				y++;
			}
			x++;
		}
	}
}

void	draw_hud(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	while (x < cub->hud.w)
	{
		y = 0;
		while (y < cub->hud.h)
		{
			if (*(cub->hud.data + x + y * cub->hud.sl / 4))
				draw_square(cub, (cub->height - cub->hud.h * 2.5)
				+ y * 2.5, x * cub->width / cub->hud.w,
				cub->hud.data[x + y * cub->hud.sl / 4]);
			y++;
		}
		x++;
	}
	draw_percent(cub);
}
