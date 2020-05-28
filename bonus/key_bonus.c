/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:46:06 by dalba-de          #+#    #+#             */
/*   Updated: 2020/03/10 14:30:01 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int		ft_mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == M_LEFT)
		cub->shoot = 1;
	return (0);
}

int		ft_mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == M_LEFT)
		cub->shoot = 0;
	return (0);
}

int		ft_key_release(int key, t_cub *cub)
{
	if (key == W)
		cub->key_up = 0;
	if (key == S)
		cub->key_down = 0;
	if (key == A)
		cub->key_left = 0;
	if (key == D)
		cub->key_right = 0;
	if (key == LEFT)
		cub->rot_left = 0;
	if (key == RIGHT)
		cub->rot_right = 0;
	if (key == SPACE)
		cub->shoot = 0;
	return (0);
}

int		ft_key_press(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	if (key == E)
		ft_pick(cub);
	if (key == W)
		cub->key_up = 1;
	if (key == S)
		cub->key_down = 1;
	if (key == A)
		cub->key_left = 1;
	if (key == D)
		cub->key_right = 1;
	if (key == LEFT)
		cub->rot_left = 1;
	if (key == RIGHT)
		cub->rot_right = 1;
	if (key == SHIFT)
		ft_open(cub);
	if (key == SPACE)
		cub->shoot = 1;
	return (0);
}
