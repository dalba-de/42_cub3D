/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:57:30 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/19 18:40:01 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int		zero_error(t_cub *cub)
{
	int x;
	int y;

	y = 0;
	while (y < cub->map_y)
	{
		x = 0;
		while (x < cub->map_x)
		{
			if (cub->map[y][x] == '0')
			{
				if (cub->map[y + 1][x] == '9' || cub->map[y - 1][x] == '9'
				|| cub->map[y][x + 1] == '9' || cub->map[y][x - 1] == '9')
					return (exit_error(-15));
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	map_error(t_cub *cub)
{
	int y;
	int x;

	y = 0;
	while (y < cub->map_y)
	{
		x = 0;
		while (x < cub->map_x)
		{
			cub->map[y][x] = f_char(x, y, cub);
			x++;
		}
		y++;
	}
	zero_error(cub);
}

int		arg_check(char *argv, char *arg)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == arg[2] && argv[i - 2] == arg[1]
	&& argv[i - 3] == arg[0] && argv[i - 4] == '.')
		return (1);
	return (0);
}
