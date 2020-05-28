/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:29:21 by dalba-de          #+#    #+#             */
/*   Updated: 2020/02/25 19:25:42 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	fill_img(t_cub *cub)
{
	cub->ray.l = 0;
	while (cub->ray.l < cub->height)
	{
		if (cub->ray.l < cub->ray.drawstart)
			pix_img(cub, cub->ceiling);
		else if (cub->ray.l >= cub->ray.drawstart &&
		cub->ray.l <= cub->ray.drawend)
			pix_img(cub, cub->ray.color);
		else
		{
			if (cub->ray.hit == 1)
				pix_img(cub, cub->floor);
		}
		cub->ray.l++;
	}
}

void	color_wall(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.stepx < 0)
			cub->ray.color = 0xDF4928;
		else
			cub->ray.color = 0x3159D0;
	}
	else
	{
		if (cub->ray.stepy > 0)
			cub->ray.color = 0x63C535;
		else
			cub->ray.color = 0xDEE427;
	}
}
