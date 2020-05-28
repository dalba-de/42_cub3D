/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 20:28:38 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 20:30:10 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	pick_ammo(t_cub *cub, int x, int y)
{
	int pid;

	cub->map[y][x] = '0';
	cub->ammo += 5;
	if (cub->ammo > 9)
		cub->ammo = 9;
	pid = fork();
	(pid == 0) ? system("aplay ./bonus/sound/reload.wav") : 0;
	(pid == 0) ? ft_bonus_close(cub) : 0;
	cub->map_spr--;
	cub->spr = list_sprites(cub);
}

void	pick_health(t_cub *cub, int x, int y)
{
	int pid;

	cub->map[y][x] = '0';
	pid = fork();
	(pid == 0) ? system("aplay ./bonus/sound/wolf/Health.wav") : 0;
	(pid == 0) ? ft_bonus_close(cub) : 0;
	cub->life += 15;
	if (cub->life > 100)
		cub->life = 100;
	cub->map_spr--;
	cub->spr = list_sprites(cub);
}

void	pick_treasure(t_cub *cub, int x, int y)
{
	int pid;

	cub->map[y][x] = '0';
	pid = fork();
	(pid == 0) ? system("aplay ./bonus/sound/coin.wav") : 0;
	(pid == 0) ? ft_bonus_close(cub) : 0;
	cub->score += 100;
	cub->map_spr--;
	cub->spr = list_sprites(cub);
}

int		ft_pick(t_cub *cub)
{
	int x;
	int y;

	x = (int)floor(cub->ray.x_pos + cub->ray.x_dir);
	y = (int)floor(cub->ray.y_pos + cub->ray.y_dir);
	if (cub->map[y][x] == 'T')
		pick_treasure(cub, x, y);
	else if (cub->map[y][x] == 'M')
		pick_ammo(cub, x, y);
	else if (cub->map[y][x] == 'H')
		pick_health(cub, x, y);
	return (0);
}
