/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:29:21 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 20:32:44 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int		check_save(char **argv)
{
	if (ft_strcmp(argv[2], "--save") > 0 ||
	ft_strlen(argv[2]) != ft_strlen("--save"))
		exit_error(-2);
	return (1);
}

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
