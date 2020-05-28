/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:10:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 17:53:41 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	draw_percent(t_cub *cub)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 15 * 10;
	while (x < 15 * 10.9)
	{
		y = 0;
		while (y < 17)
		{
			if (*(cub->numeros.data + x + y * cub->numeros.sl / 4))
				draw_square(cub, (cub->height - 30 - cub->numeros.h
				* 2.5) + y * 2.5, 272 + i * 3,
				cub->numeros.data[x + y * cub->numeros.sl / 4]);
			y++;
		}
		i++;
		x++;
	}
}

int		select_y_marine(t_cub *cub)
{
	if (cub->life >= 80)
		return (0);
	else if (cub->life >= 60 && cub->life < 80)
		return (31);
	else if (cub->life >= 40 && cub->life < 60)
		return (62);
	else if (cub->life >= 20 && cub->life < 40)
		return (94);
	else if (cub->life > 0 && cub->life < 20)
		return (127);
	else if (cub->life == 0)
		return (160);
	return (0);
}

int		select_x_marine(t_cub *cub)
{
	if (cub->key_right == 1)
		return (0);
	else if (cub->key_left == 1)
		return (52);
	else
		return (26);
}

void	draw_marine(t_cub *cub)
{
	t_point p;

	if (cub->life > 0)
		p.start_x = select_x_marine(cub);
	else
		p.start_x = 0;
	p.end_x = p.start_x + 24;
	p.x = 0;
	while (p.start_x < p.end_x)
	{
		p.y = 0;
		p.start_y = select_y_marine(cub);
		p.end_y = p.start_y + 28;
		while (p.start_y++ < p.end_y)
		{
			if (*(cub->txt[11].data + p.start_x + p.start_y *
			cub->txt[11].sl / 4))
				draw_square(cub, (cub->height - 32 * 2.2) + p.y * 2.2,
				((cub->width / 2) - 50) + p.x * 3,
				cub->txt[11].data[p.start_x + p.start_y * cub->txt[11].sl / 4]);
			p.y++;
		}
		p.x++;
		p.start_x++;
	}
}

void	draw_score(t_cub *cub)
{
	t_score	s;

	s.frame = 0;
	s.score = cub->score;
	while (s.score >= 0)
	{
		s.rest = s.score % 10;
		s.i = 0;
		s.x = 15 * s.rest;
		while (s.x < 15 * (s.rest + 1))
		{
			s.y = 0;
			while (s.y++ < 17)
				if (*(cub->numeros.data + s.x + s.y * cub->numeros.sl / 4))
					draw_square(cub, (cub->height - 30 - cub->numeros.h
					* 2.5) + s.y * 2.5, (570 - s.frame) + s.i * 2.5,
					cub->numeros.data[s.x + s.y * cub->numeros.sl / 4]);
			s.i++;
			s.x++;
		}
		s.frame += 40;
		s.score /= 10;
		if (s.score == 0)
			s.score = -1;
	}
}
