/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quest_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:15:30 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/22 18:04:11 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	ft_reset(t_cub *cub)
{
	int i;

	i = 0;
	cub->width = 0;
	cub->height = 0;
	cub->floor = 0;
	cub->ceiling = 0;
	cub->err_num = 0;
	cub->err_map = 0;
	cub->err_pos = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->map_spr = 0;
	while (i <= 9)
	{
		cub->txt[i].path = NULL;
		i++;
	}
	cub->map = NULL;
}

int		check_win(t_cub *cub)
{
	if (cub->life <= 0)
	{
		ft_putstr("\n\nYou Lose!\n\n");
		ft_close(cub);
	}
	if (cub->score > 4000)
	{
		ft_putstr("\n\nYou Win!\n\n");
		ft_close(cub);
	}
	return (0);
}
