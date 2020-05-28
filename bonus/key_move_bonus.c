/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:51:16 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 17:05:01 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int		ft_mouse(int x, int y, t_cub *cub)
{
	double dist;

	(void)y;
	dist = (double)(x - cub->mouse) / 10;
	cub->mouse = x;
	rotate(cub, dist);
	return (0);
}

void	rotate(t_cub *cub, double i)
{
	cub->ray.old_dir_x = cub->ray.x_dir;
	cub->ray.x_dir = cub->ray.x_dir * cos(i * cub->ray.rot_speed)
	- cub->ray.y_dir * sin(i * cub->ray.rot_speed);
	cub->ray.y_dir = cub->ray.old_dir_x * sin(i * cub->ray.rot_speed)
	+ cub->ray.y_dir * cos(i * cub->ray.rot_speed);
	cub->ray.old_plane_x = cub->ray.x_plane;
	cub->ray.x_plane = cub->ray.x_plane * cos(i * cub->ray.rot_speed)
	- cub->ray.y_plane * sin(i * cub->ray.rot_speed);
	cub->ray.y_plane = cub->ray.old_plane_x * sin(i * cub->ray.rot_speed)
	+ cub->ray.y_plane * cos(i * cub->ray.rot_speed);
}

void	key_up(t_cub *cub)
{
	if (cub->map[(int)cub->ray.y_pos][(int)(cub->ray.x_pos +
	cub->ray.x_dir * cub->ray.move_speed)] == '0' ||
	cub->map[(int)cub->ray.y_pos][(int)(cub->ray.x_pos +
	cub->ray.x_dir * cub->ray.move_speed)] == 'O')
		cub->ray.x_pos += cub->ray.x_dir * cub->ray.move_speed;
	if (cub->map[(int)(cub->ray.y_pos + cub->ray.y_dir *
	cub->ray.move_speed)][(int)cub->ray.x_pos] == '0' ||
	cub->map[(int)(cub->ray.y_pos + cub->ray.y_dir *
	cub->ray.move_speed)][(int)cub->ray.x_pos] == 'O')
		cub->ray.y_pos += cub->ray.y_dir * cub->ray.move_speed;
}

void	key_down(t_cub *cub)
{
	if (cub->map[(int)cub->ray.y_pos][(int)(cub->ray.x_pos - cub->ray.x_dir *
	cub->ray.move_speed)] == '0' ||
	cub->map[(int)cub->ray.y_pos][(int)(cub->ray.x_pos - cub->ray.x_dir *
	cub->ray.move_speed)] == 'O')
		cub->ray.x_pos -= cub->ray.x_dir * cub->ray.move_speed;
	if (cub->map[(int)(cub->ray.y_pos -
	cub->ray.y_dir * cub->ray.move_speed)][(int)cub->ray.x_pos] == '0' ||
	cub->map[(int)(cub->ray.y_pos -
	cub->ray.y_dir * cub->ray.move_speed)][(int)cub->ray.x_pos] == 'O')
		cub->ray.y_pos -= cub->ray.y_dir * cub->ray.move_speed;
}

void	move_lateral(t_cub *cub, char c)
{
	cub->ray.x_pos -= c * (cub->ray.y_dir * cub->ray.move_speed);
	if (cub->map[(int)cub->ray.y_pos][(int)cub->ray.x_pos] != '0' &&
	cub->map[(int)cub->ray.y_pos][(int)cub->ray.x_pos] != 'O')
		cub->ray.x_pos += c * (cub->ray.y_dir * cub->ray.move_speed);
	cub->ray.y_pos += c * (cub->ray.x_dir * cub->ray.move_speed);
	if (cub->map[(int)cub->ray.y_pos][(int)cub->ray.x_pos] != '0' &&
	cub->map[(int)cub->ray.y_pos][(int)cub->ray.x_pos] != 'O')
		cub->ray.y_pos -= c * (cub->ray.x_dir * cub->ray.move_speed);
}
