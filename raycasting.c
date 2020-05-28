/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:31:29 by dalba-de          #+#    #+#             */
/*   Updated: 2020/02/28 09:16:33 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	wall(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.mapx < cub->ray.x_pos)
			cub->ray.walldir = 'W';
		else
			cub->ray.walldir = 'E';
		cub->ray.walldist = (cub->ray.mapx - cub->ray.x_pos +
		(1 - cub->ray.stepx) / 2) / cub->ray.raydir_x;
		cub->ray.wall_x = cub->ray.y_pos + cub->ray.walldist
		* cub->ray.raydir_y;
	}
	else
	{
		if (cub->ray.mapy < cub->ray.y_pos)
			cub->ray.walldir = 'N';
		else
			cub->ray.walldir = 'S';
		cub->ray.walldist = (cub->ray.mapy - cub->ray.y_pos +
		(1 - cub->ray.stepy) / 2) / cub->ray.raydir_y;
		cub->ray.wall_x = cub->ray.x_pos + cub->ray.walldist
		* cub->ray.raydir_x;
	}
	if (cub->ray.walldist <= 0.05)
		cub->ray.walldist = 0.05;
	cub->zbuffer[cub->ray.x] = cub->ray.walldist;
}

void	dda1(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sidedistx < cub->ray.sidedisty)
		{
			cub->ray.sidedistx += cub->ray.deltadistx;
			cub->ray.mapx += cub->ray.stepx;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sidedisty += cub->ray.deltadisty;
			cub->ray.mapy += cub->ray.stepy;
			cub->ray.side = 1;
		}
		if (cub->map[cub->ray.mapy][cub->ray.mapx] == '1')
			cub->ray.hit = 1;
	}
}

void	dda(t_cub *cub)
{
	if (cub->ray.raydir_x < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.sidedistx = (cub->ray.x_pos - cub->ray.mapx)
		* cub->ray.deltadistx;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.sidedistx = (cub->ray.mapx + 1.0 - cub->ray.x_pos)
		* cub->ray.deltadistx;
	}
	if (cub->ray.raydir_y < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.sidedisty = (cub->ray.y_pos - cub->ray.mapy)
		* cub->ray.deltadisty;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.sidedisty = (cub->ray.mapy + 1.0 - cub->ray.y_pos)
		* cub->ray.deltadisty;
	}
}

void	inits_raycast(t_cub *cub)
{
	cub->ray.cam = 2 * cub->ray.x / (double)cub->width - 1;
	cub->ray.raydir_x = cub->ray.x_dir + cub->ray.x_plane * cub->ray.cam;
	cub->ray.raydir_y = cub->ray.y_dir + cub->ray.y_plane * cub->ray.cam;
	cub->ray.mapx = (int)cub->ray.x_pos;
	cub->ray.mapy = (int)cub->ray.y_pos;
	cub->ray.hit = 0;
	cub->ray.side = 0;
	cub->ray.deltadistx = sqrt(1 + (cub->ray.raydir_y * cub->ray.raydir_y)
	/ (cub->ray.raydir_x * cub->ray.raydir_x));
	cub->ray.deltadisty = sqrt(1 + (cub->ray.raydir_x * cub->ray.raydir_x)
	/ (cub->ray.raydir_y * cub->ray.raydir_y));
}

int		raycast(t_cub *cub)
{
	cub->ray.x = 0;
	while (cub->ray.x < cub->width)
	{
		inits_raycast(cub);
		dda(cub);
		dda1(cub);
		wall(cub);
		lengthline(cub);
		if (cub->key_text)
		{
			select_texture(cub);
			check_x_text(cub);
			draw(cub);
		}
		else
		{
			color_wall(cub);
			fill_img(cub);
		}
		cub->ray.x++;
	}
	ft_sprite(cub);
	return (0);
}
