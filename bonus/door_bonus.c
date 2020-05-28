/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:23:33 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/22 17:26:55 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int		ft_secretdoor(t_cub *cub)
{
	int x;
	int y;
	int pid;

	x = (int)floor(cub->ray.x_pos + cub->ray.x_dir);
	y = (int)floor(cub->ray.y_pos + cub->ray.y_dir);
	if (cub->map[y][x] == 'X')
	{
		cub->map[y][x] = '0';
		pid = fork();
		(pid == 0) ? system("aplay ./bonus/sound/secret.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
		return (1);
	}
	return (0);
}

int		ft_door(t_cub *cub)
{
	int x;
	int y;
	int pid;

	x = (int)floor(cub->ray.x_pos + cub->ray.x_dir);
	y = (int)floor(cub->ray.y_pos + cub->ray.y_dir);
	if (cub->map[y][x] == 'D')
	{
		cub->map[y][x] = 'O';
		pid = fork();
		(pid == 0) ? system("aplay ./bonus/sound/open.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
		return (1);
	}
	else if (cub->map[y][x] == 'O')
	{
		cub->map[y][x] = 'D';
		pid = fork();
		(pid == 0) ? system("aplay ./bonus/sound/close.wav") : 0;
		(pid == 0) ? ft_bonus_close(cub) : 0;
		return (1);
	}
	return (0);
}

void	ft_open(t_cub *cub)
{
	int x;
	int y;

	x = (int)floor(cub->ray.x_pos + cub->ray.x_dir);
	y = (int)floor(cub->ray.y_pos + cub->ray.y_dir);
	if (cub->map[y][x] == 'L')
	{
		ft_reset(cub);
		cub->level++;
		parser(cub, "./maps/level2.cub");
		return ;
	}
	if (ft_secretdoor(cub) == 1)
		return ;
	else if (ft_door(cub) == 1)
		return ;
}
