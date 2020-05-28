/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:51:48 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/19 18:36:16 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		check_w(int x, int y, t_cub *cub)
{
	while (x >= 0)
	{
		if (cub->map[y][x] == '1')
			return (1);
		x--;
	}
	return (0);
}

int		check_e(int x, int y, t_cub *cub)
{
	while (x < cub->map_x)
	{
		if (cub->map[y][x] == '1')
			return (1);
		x++;
	}
	return (0);
}

int		check_s(int x, int y, t_cub *cub)
{
	while (y < cub->map_y)
	{
		if (cub->map[y][x] == '1')
			return (1);
		y++;
	}
	return (0);
}

int		check_n(int x, int y, t_cub *cub)
{
	while (y >= 0)
	{
		if (cub->map[y][x] == '1')
			return (1);
		y--;
	}
	return (0);
}

char	f_char(int x, int y, t_cub *cub)
{
	if (cub->map[y][x] == '1')
		return ('1');
	else
	{
		if (check_n(x, y, cub) && check_s(x, y, cub)
		&& check_e(x, y, cub) && check_w(x, y, cub))
			return (cub->map[y][x]);
	}
	return ('9');
}
