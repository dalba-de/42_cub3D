/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:53:15 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/07 18:53:22 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	weapon_sound(t_cub *cub)
{
	int	pid;

	cub->step_shoot = 1;
	if (cub->ammo > 0)
	{
		pid = fork();
		(pid == 0) ? system("aplay ./bonus/sound/pistol.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
		cub->ammo--;
	}
	else
	{
		pid = fork();
		(pid == 0) ? system("aplay ./bonus/sound/knife.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
	}
}

void	shoot_animation(t_cub *cub)
{
	static unsigned int i;
	static unsigned int mem;

	if (i++ >= 3)
	{
		if ((mem == 0) && cub->shoot == 1)
		{
			weapon_sound(cub);
		}
		if (mem == 1 && cub->shoot == 1)
			cub->step_shoot += 1;
		if (mem == 1 && cub->shoot == 0)
			cub->step_shoot = 0;
		if (mem == 2 && cub->shoot == 1)
			cub->step_shoot -= 1;
		if (mem == 2 && cub->shoot == 0)
			cub->step_shoot = 1;
		if (cub->shoot == 0)
			cub->step_shoot = 0;
		mem = cub->step_shoot;
	}
	if (i > 3)
		i = 0;
}

void	draw_weapon(t_cub *cub)
{
	t_point p;
	t_txt	*wea_img;

	if (cub->ammo > 0)
		wea_img = &cub->weap[cub->step_shoot];
	else
		wea_img = &cub->knife[cub->step_shoot];
	p.start_x = (cub->width / 2) - (wea_img->w / 2);
	p.end_x = p.start_x + wea_img->w;
	p.start_y = cub->height - wea_img->h;
	p.end_y = cub->height;
	p.x = 0;
	while ((p.x + p.start_x) < p.end_x)
	{
		p.y = 0;
		while ((p.y + p.start_y) < p.end_y)
		{
			if (*(wea_img->data + p.x + p.y * wea_img->sl / 4))
				draw_square(cub, (cub->height - (wea_img->h * 1.5) -
				(cub->hud.h * 2.5)) + p.y * 1.5, (cub->width / 1.9) + p.x * 1.5,
				wea_img->data[p.x + p.y * wea_img->sl / 4]);
			p.y++;
		}
		p.x++;
	}
}
