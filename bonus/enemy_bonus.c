/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 18:50:26 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 17:02:24 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	get_shot(t_cub *cub, t_spr *spr)
{
	int pid;

	if (spr->v == 1)
	{
		pid = fork();
		if (cub->level == 1)
			(pid == 0) ? system("aplay ./bonus/sound/achtung.wav") : 0;
		else
			(pid == 0) ? system("aplay ./bonus/sound/demon_seen.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
	}
	if (spr->v % 3 == 0)
	{
		cub->life -= 1;
		spr->getshot = 1;
		pid = fork();
		if (cub->level == 1)
			(pid == 0) ? system("aplay ./bonus/sound/shot.wav") : 0;
		else
			(pid == 0) ? system("aplay ./bonus/sound/imp_attack.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
	}
}

void	hit_sprite(t_cub *cub, int i)
{
	int pid;

	if (cub->step_shoot == 1)
	{
		cub->spr[cub->sprorder[i]].hit = 1;
		if (cub->spr[cub->sprorder[i]].life > 0)
		{
			cub->spr[cub->sprorder[i]].hit = 1;
			cub->spr[cub->sprorder[i]].life -= 10;
		}
		else
		{
			cub->spr[cub->sprorder[i]].c = 'M';
			cub->map[(int)(cub->spr[cub->sprorder[i]].y)]
			[(int)(cub->spr[cub->sprorder[i]].x)] = 'M';
			cub->score += 500;
			pid = fork();
			if (cub->level == 1)
				(pid == 0) ? system("aplay ./bonus/sound/death.wav") : 0;
			else
				(pid == 0) ? system("aplay ./bonus/sound/demon_death.wav") : 0;
			(pid == 0) ? ft_bonus_close(cub) : 0;
		}
	}
}

void	on_shoot(t_cub *cub, t_sprtools *stools, int i)
{
	int x;
	int y;

	if (cub->ammo > 0)
	{
		if (stools->x == cub->width / 2
		&& stools->y == cub->height / 2
		&& cub->step_shoot == 1
		&& cub->spr[cub->sprorder[i]].rip == 0)
			hit_sprite(cub, i);
		else if (cub->step_shoot != 1)
			cub->spr[cub->sprorder[i]].hit = 0;
	}
	else
	{
		x = (int)floor(cub->ray.x_pos + cub->ray.x_dir);
		y = (int)floor(cub->ray.y_pos + cub->ray.y_dir);
		if (stools->x == cub->width / 2 && stools->y ==
		cub->height / 2 && cub->map[y][x] == 'B' &&
		cub->step_shoot == 1
		&& cub->spr[cub->sprorder[i]].rip == 0)
			hit_sprite(cub, i);
		else if (cub->step_shoot != 1)
			cub->spr[cub->sprorder[i]].hit = 0;
	}
}

int		anim_text(t_spr *spr)
{
	if (spr->rip == 0 && spr->hit == 1)
		return (1);
	else if (spr->rip == 1)
		return (2);
	else if (spr->getshot == 1)
		return (3);
	else
		return (0);
}

void	draw_sprite_enemy(t_sprtools *stools, t_cub *cub, int i)
{
	stools->x = stools->drawstart_x;
	while (stools->x++ < stools->drawend_x)
	{
		stools->tex_x = (int)((stools->x - ((-1 * stools->width) /
		2 + stools->screen)) * cub->enemy[cub->sp_state].w / stools->width);
		if (stools->transf_y > 0 && stools->x >= 0 && stools->x
		< cub->width && stools->transf_y < cub->zbuffer[stools->x])
		{
			stools->y = stools->drawstart_y;
			while (stools->y++ < stools->drawend_y)
			{
				stools->d = stools->y * 256 - cub->height * 128 +
				stools->height * 128;
				stools->tex_y = ((stools->d * cub->enemy[cub->sp_state].h) /
				stools->height) / 256;
				if (*(cub->enemy[cub->sp_state].data +
				stools->tex_x + stools->tex_y
				* cub->enemy[cub->sp_state].sl / 4))
					draw_dot(cub, stools->x, stools->y,
					cub->enemy[cub->sp_state].data[stools->tex_x +
					stools->tex_y * cub->enemy[cub->sp_state].sl / 4]);
				on_shoot(cub, stools, i);
			}
		}
	}
}
