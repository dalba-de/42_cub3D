/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:43:32 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/22 17:52:45 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	draw_square(t_cub *cub, int x, int y, int color)
{
	int i;
	int j;
	int width;
	int height;

	i = x;
	j = y;
	height = 6;
	width = height;
	while (i < width + x)
	{
		j = y;
		while (j < height + y)
		{
			draw_dot(cub, j, i, color);
			j++;
		}
		i++;
	}
}

void	minimap_color(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == '1' || cub->map[i][j] == 'X')
		cub->minimap.color = 0x0;
	else if (cub->map[i][j] == '2')
		cub->minimap.color = 0x31EB21;
	else if (cub->map[i][j] == '0' || cub->map[i][j] == 'D' ||
			cub->map[i][j] == 'O')
		cub->minimap.color = 0xbbafae;
	else if (cub->map[i][j] == 'T')
		cub->minimap.color = 0xe4af0a;
	else if (cub->map[i][j] == 'B')
		cub->minimap.color = 0x892565;
	else if (cub->map[i][j] == 'H')
		cub->minimap.color = 0xdf01a5;
}

void	minimap(t_cub *cub)
{
	int i;
	int j;

	cub->minimap.start = cub->width / 1.13 - (cub->map_x * 6) / 2;
	i = 0;
	while (i < cub->map_y)
	{
		j = 0;
		while (cub->map[i][j])
		{
			minimap_color(cub, i, j);
			if (cub->minimap.color != 0x0)
				draw_square(cub, (cub->height - cub->map_y * 6)
				+ 2 + i * 6, cub->minimap.start + j
				* 6, cub->minimap.color);
			j++;
		}
		i++;
	}
	draw_square(cub, (cub->height - cub->map_y * 6) + 2 +
	(cub->ray.y_pos - 0.5) * 6, cub->minimap.start
	+ cub->ray.x_pos * 6, 0xFF0000);
}
