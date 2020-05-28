/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:51:16 by dalba-de          #+#    #+#             */
/*   Updated: 2020/02/28 08:42:42 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	rotate_left(t_cub *cub)
{
	cub->ray.old_dir_x = cub->ray.x_dir;
	cub->ray.x_dir = cub->ray.x_dir * cos(-1 * cub->ray.rot_speed)
	- cub->ray.y_dir * sin(-1 * cub->ray.rot_speed);
	cub->ray.y_dir = cub->ray.old_dir_x * sin(-1 * cub->ray.rot_speed)
	+ cub->ray.y_dir * cos(-1 * cub->ray.rot_speed);
	cub->ray.old_plane_x = cub->ray.x_plane;
	cub->ray.x_plane = cub->ray.x_plane * cos(-1 * cub->ray.rot_speed)
	- cub->ray.y_plane * sin(-1 * cub->ray.rot_speed);
	cub->ray.y_plane = cub->ray.old_plane_x * sin(-1 * cub->ray.rot_speed)
	+ cub->ray.y_plane * cos(-1 * cub->ray.rot_speed);
}

void	rotate_right(t_cub *cub)
{
	cub->ray.old_dir_x = cub->ray.x_dir;
	cub->ray.x_dir = cub->ray.x_dir * cos(cub->ray.rot_speed)
	- cub->ray.y_dir * sin(cub->ray.rot_speed);
	cub->ray.y_dir = cub->ray.old_dir_x * sin(cub->ray.rot_speed)
	+ cub->ray.y_dir * cos(cub->ray.rot_speed);
	cub->ray.old_plane_x = cub->ray.x_plane;
	cub->ray.x_plane = cub->ray.x_plane * cos(cub->ray.rot_speed)
	- cub->ray.y_plane * sin(cub->ray.rot_speed);
	cub->ray.y_plane = cub->ray.old_plane_x * sin(cub->ray.rot_speed)
	+ cub->ray.y_plane * cos(cub->ray.rot_speed);
}

void	key_up(t_cub *cub)
{
	if (cub->map[(int)cub->ray.y_pos][(int)(cub->ray.x_pos +
	cub->ray.x_dir * cub->ray.move_speed)] != '1')
		cub->ray.x_pos += cub->ray.x_dir * cub->ray.move_speed;
	if (cub->map[(int)(cub->ray.y_pos + cub->ray.y_dir *
	cub->ray.move_speed)][(int)cub->ray.x_pos] != '1')
		cub->ray.y_pos += cub->ray.y_dir * cub->ray.move_speed;
}

void	key_down(t_cub *cub)
{
	if (cub->map[(int)cub->ray.y_pos][(int)(cub->ray.x_pos - cub->ray.x_dir *
	cub->ray.move_speed)] != '1')
		cub->ray.x_pos -= cub->ray.x_dir * cub->ray.move_speed;
	if (cub->map[(int)(cub->ray.y_pos -
	cub->ray.y_dir * cub->ray.move_speed)][(int)cub->ray.x_pos] != '1')
		cub->ray.y_pos -= cub->ray.y_dir * cub->ray.move_speed;
}

void	move_lateral(t_cub *cub, char c)
{
	cub->ray.x_pos -= c * (cub->ray.y_dir * cub->ray.move_speed);
	if (cub->map[(int)cub->ray.y_pos][(int)cub->ray.x_pos] == '1')
		cub->ray.x_pos += c * (cub->ray.y_dir * cub->ray.move_speed);
	cub->ray.y_pos += c * (cub->ray.x_dir * cub->ray.move_speed);
	if (cub->map[(int)cub->ray.y_pos][(int)cub->ray.x_pos] == '1')
		cub->ray.y_pos -= c * (cub->ray.x_dir * cub->ray.move_speed);
}
