/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:11:37 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/08 19:28:31 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

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

void	draw_sprite(t_sprtools *stools, t_cub *cub, t_txt *txt)
{
	stools->x = stools->drawstart_x;
	while (stools->x < stools->drawend_x)
	{
		stools->tex_x = (int)((stools->x - ((-1 * stools->width) /
		2 + stools->screen)) * txt->w / stools->width);
		if (stools->transf_y > 0 && stools->x >= 0 && stools->x
		< cub->width && stools->transf_y < cub->zbuffer[stools->x])
		{
			stools->y = stools->drawstart_y;
			while (stools->y < stools->drawend_y)
			{
				stools->d = stools->y * 256 - cub->height * 128 +
				stools->height * 128;
				stools->tex_y = ((stools->d * txt->h) /
				stools->height) / 256;
				if (*(txt->data + stools->tex_x + stools->tex_y
				* txt->sl / 4))
					draw_dot(cub, stools->x, stools->y,
					txt->data[stools->tex_x +
					stools->tex_y * txt->sl / 4]);
				stools->y++;
			}
		}
		stools->x++;
	}
}
