/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:33:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/19 18:30:55 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		fill_sprites(t_cub *cub, t_spr *spr, t_ints *e)
{
	spr[e->i].y = e->j + 0.5;
	spr[e->i].x = e->k + 0.5;
	spr[e->i].c = cub->map[e->j][e->k];
	spr[e->i].life = 100;
	spr[e->i].hit = 0;
	spr[e->i].rip = 0;
	spr[e->i].v = 0;
	spr[e->i].getshot = 0;
}

t_spr		*list_sprites(t_cub *cub)
{
	t_ints	e;
	t_spr	*spr;

	spr = malloc(cub->map_spr * sizeof(t_spr));
	cub->sprorder = malloc(cub->map_spr * sizeof(int));
	e.i = 0;
	e.j = -1;
	while (++e.j < cub->map_y)
	{
		e.k = -1;
		while (++e.k < cub->map_x)
		{
			if (cub->map[e.j][e.k] == '2' || cub->map[e.j][e.k] == 'T'
			|| cub->map[e.j][e.k] == 'B' || cub->map[e.j][e.k] == 'M'
			|| cub->map[e.j][e.k] == 'H' || cub->map[e.j][e.k] == '3'
			|| cub->map[e.j][e.k] == '4' || cub->map[e.j][e.k] == '5')
			{
				fill_sprites(cub, spr, &e);
				e.i++;
			}
		}
	}
	return (spr);
}

void		locate_dir(t_cub *cub, char c)
{
	if (c == 'N' || c == 'S')
	{
		cub->ray.x_dir = 0;
		cub->ray.y_dir = (c == 'S' ? 1 : -1);
		cub->ray.x_plane = (c == 'S' ? -0.66 : 0.66);
		cub->ray.y_plane = 0;
	}
	if (c == 'E' || c == 'W')
	{
		cub->ray.y_dir = 0;
		cub->ray.x_dir = (c == 'E' ? 1 : -1);
		cub->ray.y_plane = (c == 'W' ? -0.66 : 0.66);
		cub->ray.x_plane = 0;
	}
}

void		check_map_positions(t_cub *cub, int j, int i)
{
	if (cub->map[j][i] == 'N' || cub->map[j][i] == 'S'
	|| cub->map[j][i] == 'E' || cub->map[j][i] == 'W')
	{
		cub->ray.x_pos = i + 0.5;
		cub->ray.y_pos = j + 0.5;
		cub->err_pos++;
		locate_dir(cub, cub->map[j][i]);
		cub->map[j][i] = '0';
	}
}

int			locate_pos(t_cub *cub)
{
	int i;
	int j;

	j = 0;
	while (j < cub->map_y)
	{
		i = 0;
		while (i < cub->map_x)
		{
			check_map_positions(cub, j, i);
			i++;
		}
		j++;
	}
	if (cub->err_pos > 1 || cub->err_pos <= 0)
		return (exit_error(-14));
	if (cub->map_spr == 0)
		return (exit_error(-13));
	return (0);
}
